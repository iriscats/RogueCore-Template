#pragma once
#include "CoreMinimal.h"
#include "BehaviorTree/BTService.h"
#include "BehaviorTree/BehaviorTreeTypes.h"
#include "BTService_UpdateMoveInFormation.generated.h"

UCLASS(Blueprintable)
class UBTService_UpdateMoveInFormation : public UBTService {
    GENERATED_BODY()
    

public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float LookAheadTime;
    
    FBlackboardKeySelector TargetLocationKey;
    float AttackerRadius;
    UBTService_UpdateMoveInFormation();
};
