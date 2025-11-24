#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Components/ActorComponent.h"
#include "EInputKeys.h"
#include "RecallDelegateDelegate.h"
#include "RecallableProjectileComponent.generated.h"

class APlayerCharacter;
class UInstantUsable;
class UInterpolatedFirstPersonStaticMeshComponent;
class USceneComponent;
UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class URecallableProjectileComponent : public UActorComponent {
    GENERATED_BODY()
    // UPROPERTY fields moved from private section

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Replicated, meta=(AllowPrivateAccess=true))

    APlayerCharacter* RecallTarget;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))

    FVector EndRotationOffset;

    float RecallStartTime;

    float RecallSpeed;

    FTransform StartTransform;

    UInterpolatedFirstPersonStaticMeshComponent* FPMeshComponent;

    bool IsRecallable;

    URecallableProjectileComponent(const FObjectInitializer& ObjectInitializer);

    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;



public:
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FRecallDelegate OnCollectRecallable;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, Transient, meta=(AllowPrivateAccess=true))
    USceneComponent* UpdatedComponent;
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UInstantUsable* usable;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Replicated, meta=(AllowPrivateAccess=true))
    APlayerCharacter* RecallTarget;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FVector EndRotationOffset;
    float RecallStartTime;
    float RecallSpeed;
    FTransform StartTransform;
    UInterpolatedFirstPersonStaticMeshComponent* FPMeshComponent;
    bool IsRecallable;
    URecallableProjectileComponent(const FObjectInitializer& ObjectInitializer);
    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
    UFUNCTION(BlueprintCallable, Reliable, Server)
    void Server_SetRecallTarget(APlayerCharacter* Player, const FTransform& startTrans);
    UFUNCTION(BlueprintCallable)
    void OnUsedBy(APlayerCharacter* Player, EInputKeys Key);
};
