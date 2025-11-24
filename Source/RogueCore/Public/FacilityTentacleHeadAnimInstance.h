#pragma once
#include "CoreMinimal.h"
#include "EnemyAnimInstance.h"
#include "FacilityTentacleHeadAnimInstance.generated.h"

UCLASS(Blueprintable, NonTransient)
class UFacilityTentacleHeadAnimInstance : public UEnemyAnimInstance {
    GENERATED_BODY()
    // UPROPERTY fields moved from protected section

public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    bool Searching;
    
    bool Melee;
    bool RangedAttack;
    UFacilityTentacleHeadAnimInstance();
};
