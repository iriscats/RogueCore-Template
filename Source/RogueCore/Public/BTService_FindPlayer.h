#pragma once
#include "CoreMinimal.h"
#include "BehaviorTree/BTService.h"
#include "BehaviorTree/BehaviorTreeTypes.h"
#include "BTService_FindPlayer.generated.h"

class APlayerCharacter;
UCLASS(Blueprintable)
class UBTService_FindPlayer : public UBTService {
    GENERATED_BODY()
    // UPROPERTY fields moved from protected section


public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FBlackboardKeySelector TargetKey;
    
    bool MustBeAlive;
    bool SwithToBetterTargets;
    bool RegisterForPositioning;
    bool IsFlying;
    bool CanShoot;
    bool OwnerIsMultiTargeter;
    float TargetingRange;
    APlayerCharacter* CurrentRegisteredTarget;
    UBTService_FindPlayer();
};
