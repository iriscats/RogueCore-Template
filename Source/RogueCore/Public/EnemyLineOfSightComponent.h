#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "LoSDelegateDelegate.h"
#include "EnemyLineOfSightComponent.generated.h"

class UMeshComponent;
UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class ROGUECORE_API UEnemyLineOfSightComponent : public UActorComponent {
    GENERATED_BODY()
    // UPROPERTY fields moved from protected section
public:
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FLoSDelegate OnGaindedLineOfSight;
    
    FLoSDelegate OnLostLineOfSight;
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UMeshComponent* OwnerMesh;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName LoSFromSocketName;
    float LoSInterval;
    float LoSIntervalVariance;
    bool AutoSetupOwnerMesh;
    UEnemyLineOfSightComponent(const FObjectInitializer& ObjectInitializer);
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool HasLineOfSight() const;
    bool GetIsDetecting() const;
    UFUNCTION(BlueprintCallable)
    void AsyncTrace();
};
