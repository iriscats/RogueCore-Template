#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "ChangedStateSigDelegate.h"
#include "StateStats.h"
#include "GroundToAirComponent.generated.h"

class ADeepPathfinderCharacter;
class UDeepPathfinderMovement;
UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class UGroundToAirComponent : public UActorComponent {
    GENERATED_BODY()
    // UPROPERTY fields moved from protected section
public:
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FChangedStateSig OnChangedPathfinderState;
    
 
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UDeepPathfinderMovement* CurrentMove;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float WalkTime;
    float WalkTimeMaxRandomOffset;
    float WalkTimeMinRandomOffset;
    bool WalkUseTimer;
    FStateStats WalkStats;
    float FlyTime;
    float FlyTimeMaxRandomOffset;
    float FlyTimeMinRandomOffset;
    bool FlyUseTimer;
    FStateStats FlyStats;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, ReplicatedUsing=OnRep_StateChange, meta=(AllowPrivateAccess=true))
    bool IsFlying;
    TWeakObjectPtr<ADeepPathfinderCharacter> OwningPathfinder;
    UGroundToAirComponent(const FObjectInitializer& ObjectInitializer);
    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
    UFUNCTION(BlueprintCallable)
    void SetIsFlying(bool aIsFlying);
    void SetAllowedToChangeState(bool aIsAllowed);
    UFUNCTION()
    void OnRep_StateChange();
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool GetIsWalking() const;
    bool GetIsFlying() const;
    void Engage();
};
