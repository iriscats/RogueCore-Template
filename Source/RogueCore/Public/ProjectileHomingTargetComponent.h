#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Engine/OverlapResult.h"
#include "ProjectileHomingTargetComponent.generated.h"

class UHealthComponentBase;
UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class UProjectileHomingTargetComponent : public UActorComponent {
    GENERATED_BODY()
    // UPROPERTY fields moved from protected section

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))

    float Radius;

    float LockonDelay;

    int32 OnlyIncludePawnsWithAttitude;

    bool AquireOnBeginPlay;

    bool UnlockOnTargetDeath;

    UProjectileHomingTargetComponent(const FObjectInitializer& ObjectInitializer);

    UFUNCTION(BlueprintCallable)

    void OnTargetDeath(UHealthComponentBase* Health);



public:
protected:
    UPROPERTY(EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TArray<FOverlapResult> Targets;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float Radius;
    float LockonDelay;
    int32 OnlyIncludePawnsWithAttitude;
    bool AquireOnBeginPlay;
    bool UnlockOnTargetDeath;
    UProjectileHomingTargetComponent(const FObjectInitializer& ObjectInitializer);
    UFUNCTION(BlueprintCallable)
    void OnTargetDeath(UHealthComponentBase* Health);
    void AquireTarget();
};
