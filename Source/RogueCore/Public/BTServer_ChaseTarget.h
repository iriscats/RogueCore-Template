#pragma once
#include "CoreMinimal.h"
#include "BehaviorTree/BTService.h"
#include "BehaviorTree/BehaviorTreeTypes.h"
#include "GameplayTagContainer.h"
#include "BTServer_ChaseTarget.generated.h"

UCLASS(Blueprintable)
class UBTServer_ChaseTarget : public UBTService {
    GENERATED_BODY()
    // UPROPERTY fields moved from protected section

public:

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FBlackboardKeySelector TargetKey;
    
    bool MustBeAlive;
    bool MustBeUnparalyzed;
    bool IgnoreIncapacitated;
    bool PreferNewTarget;
    FGameplayTag SwitchTargetCooldownTag;
    FGameplayTagQuery TargetingQuery;
    bool IsFlying;
    bool CanShoot;
    float TargetingRange;
    float SwitchTargetTime;
    float SwitchTargetDeviation;
    UBTServer_ChaseTarget();
};
