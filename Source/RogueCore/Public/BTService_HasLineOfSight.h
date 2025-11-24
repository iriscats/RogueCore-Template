#pragma once
#include "CoreMinimal.h"
#include "BehaviorTree/BTService.h"
#include "BehaviorTree/BehaviorTreeTypes.h"
#include "UObject/UnrealType.h"
#include "BTService_HasLineOfSight.generated.h"

UCLASS(Blueprintable)
class ROGUECORE_API UBTService_HasLineOfSight : public UBTService {
    GENERATED_BODY()
    // UPROPERTY fields moved from protected section

public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FBlackboardKeySelector HasLineOfSightKey;
    
    FBlackboardKeySelector TargetKey;
    FName EyeSocket;
    float MaxDistance;
    TEnumAsByte<ECollisionChannel> TraceChannel;
    bool DebugDraw;
    bool InvalidateOutOfRange;
    UBTService_HasLineOfSight();
};
