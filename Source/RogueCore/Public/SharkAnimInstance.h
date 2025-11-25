#pragma once
#include "CoreMinimal.h"
#include "ESharkEnemyState.h"
#include "SpiderAnimInstance.h"
#include "SharkAnimInstance.generated.h"

UCLASS(Abstract, Blueprintable, NonTransient)
class USharkAnimInstance : public USpiderAnimInstance {
    GENERATED_BODY()
    // UPROPERTY fields moved from protected section

public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    ESharkEnemyState SharkState;
    
    bool IsCloseToGround;
    bool AttackConnected;
    bool IsAttackingAndAttackNotConnected;
    bool IsNotAttackingOrAttackConnected;
    bool IsFalling;
    bool IsVulnerable;
    float BendValue;
    bool IsTurningSharkEdition;
    float TurnSpeed;
    float IdleSpeed;
    USharkAnimInstance(const FObjectInitializer& ObjectInitializer);
};
