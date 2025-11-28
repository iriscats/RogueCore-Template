#pragma once
#include "CoreMinimal.h"

#include "UObject/UnrealType.h"
#include "AttackBaseComponent.h"
#include "BeamSweepHitSignatureDelegate.h"
#include "DelegateDelegate.h"
#include "Templates/SubclassOf.h"
#include "BeamSweepAttackComponent.generated.h"

class AActor;
class UStatusEffect;
class UTerrainMaterial;
UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class ROGUECORE_API UBeamSweepAttackComponent : public UAttackBaseComponent {
    GENERATED_BODY()
    // UPROPERTY fields moved from private section

public:
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FBeamSweepHitSignature OnBeamSweepHit;
    
    FDelegate OnStop;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UTerrainMaterial* HotRockMaterial;
    float SweepDuration;
    float SweepAngle;
    TSubclassOf<UStatusEffect> InflictedStatusEffect;
    float CarveFrequency;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    bool IsAttacking;
    TEnumAsByte<ETraceTypeQuery> TraceChannel;
 
    AActor* TargetedActor;
    TSet<AActor*> StatusEffectActors;
    UBeamSweepAttackComponent(const FObjectInitializer& ObjectInitializer);
    UFUNCTION(BlueprintCallable, NetMulticast, Reliable)
    void StopAttackMulticast();
    UFUNCTION(BlueprintCallable, NetMulticast, Reliable)
    void StartAttackMulticast(FVector sweepStartDirection, FVector sweepEndDirection);
};
