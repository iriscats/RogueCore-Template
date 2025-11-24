#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "EWoodLouseState.h"
#include "SpiderAnimInstance.h"
#include "WoodLouseAnimInstance.generated.h"

UCLASS(Blueprintable, NonTransient)
class UWoodLouseAnimInstance : public USpiderAnimInstance {
    GENERATED_BODY()
    // UPROPERTY fields moved from protected section

public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    FVector2D AngleToTarget;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float InterpSpeed;
    float BreakRollingWhenTimeLeft;
    EWoodLouseState RollerState;
    bool IsWalking;
    bool IsUpRight;
    bool IsDoingSpecialAttack;
    bool IsUnFolded;
    bool IsGroundValid;
    bool IsInRollState;
    bool IdleToDownTurnLeftLock;
    bool DownTurnLeftToIdleLock;
    bool DownWalkToDownTurnLeftLock;
    bool WoodlouseWalk;
    bool IdleToDownWalkLock;
    bool DownWalkToDownTurnRightLock;
    bool IdleToDownTurnRightLock;
    UWoodLouseAnimInstance();
};
