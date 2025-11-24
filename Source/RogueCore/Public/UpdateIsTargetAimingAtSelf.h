#pragma once
#include "CoreMinimal.h"
#include "BehaviorTree/BTService.h"
#include "BehaviorTree/BehaviorTreeTypes.h"
#include "UObject/NoExportTypes.h"
#include "UpdateIsTargetAimingAtSelf.generated.h"

UCLASS(Blueprintable)
class ROGUECORE_API UUpdateIsTargetAimingAtSelf : public UBTService {
    GENERATED_BODY()
    // UPROPERTY fields moved from protected section

public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FBlackboardKeySelector TargetKey;
    
    FBlackboardKeySelector IsTargetAimingAtSelfKey;
    float AimPointRadius;
    FVector SelfOffset;
    UUpdateIsTargetAimingAtSelf();
};
