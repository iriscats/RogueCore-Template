#pragma once
#include "CoreMinimal.h"
#include "BehaviorTree/BTService.h"
#include "BehaviorTree/BehaviorTreeTypes.h"
#include "EPloverPositioningMode.h"
#include "BTService_GetPloverAttachPoints.generated.h"

class UPloverTargetSockets;
UCLASS(Blueprintable)
class ROGUECORE_API UBTService_GetPloverAttachPoints : public UBTService {
    GENERATED_BODY()
    // UPROPERTY fields moved from protected section

public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UPloverTargetSockets* TargetPoints;
    
    float PositioningMaxRange;
    float PositioningMinRange;
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    EPloverPositioningMode PositioningMode;
    FBlackboardKeySelector TargetKey;
    FBlackboardKeySelector TargetLocationKey;
    UBTService_GetPloverAttachPoints();
};
