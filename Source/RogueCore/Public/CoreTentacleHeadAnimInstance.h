#pragma once
#include "CoreMinimal.h"
#include "EnemyAnimInstance.h"
#include "CoreTentacleHeadAnimInstance.generated.h"

UCLASS(Abstract, Blueprintable, NonTransient)
class UCoreTentacleHeadAnimInstance : public UEnemyAnimInstance {
    GENERATED_BODY()
    // UPROPERTY fields moved from protected section
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    bool Searching;
    
    bool MeleeAttack;
    bool RangedAttack;
    bool GrabAttack;
    bool GrabShake;
    UCoreTentacleHeadAnimInstance();
};
