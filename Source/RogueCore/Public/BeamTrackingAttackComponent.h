#pragma once
#include "CoreMinimal.h"

#include "UObject/UnrealType.h"
#include "AttackBaseComponent.h"
#include "BeamSweepHitSignatureDelegate.h"
#include "DelegateDelegate.h"
#include "Templates/SubclassOf.h"
#include "BeamTrackingAttackComponent.generated.h"

class AActor;
class UStatusEffect;
class UTerrainMaterial;
UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class ROGUECORE_API UBeamTrackingAttackComponent : public UAttackBaseComponent {
    GENERATED_BODY()
    // UPROPERTY fields moved from private section

public:
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FBeamSweepHitSignature OnBeamSweepHit;
    
    FDelegate OnTelegraphFinished;
    FDelegate OnAttackStart;
    FDelegate OnAttackEnd;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float TelegraphDuration;
    float AttackDuration;
    float TrackingSpeed;
    UTerrainMaterial* HotRockMaterial;
    float CarveFrequency;
    TEnumAsByte<ETraceTypeQuery> TraceChannel;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Replicated, Transient, meta=(AllowPrivateAccess=true))
    bool IsAttacking;
    TArray<TEnumAsByte<EObjectTypeQuery>> ObjectTypes;
    UClass* ActorClassFilter;
    TSubclassOf<UStatusEffect> InflictedStatusEffect;
    bool IsTelegraphFinished;
 
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    AActor* TargetedActor;
    FVector CurrentDirection;
    TArray<AActor*> OverlappedActorsPrev;
    UBeamTrackingAttackComponent(const FObjectInitializer& ObjectInitializer);
    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
    UFUNCTION(BlueprintCallable, NetMulticast, Reliable)
    void StopAttackMulticast();
    UFUNCTION(BlueprintCallable, NetMulticast, Reliable)
    void StartAttackMulticast(FVector Direction, AActor* NewTargetedActor);
};
