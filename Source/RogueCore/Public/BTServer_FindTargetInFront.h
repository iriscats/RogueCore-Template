#pragma once
#include "CoreMinimal.h"
#include "BehaviorTree/BTService.h"
#include "BehaviorTree/BehaviorTreeTypes.h"
#include "BTServer_FindTargetInFront.generated.h"

UCLASS(Blueprintable)
class ROGUECORE_API UBTServer_FindTargetInFront : public UBTService {
    GENERATED_BODY()
    
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FBlackboardKeySelector TargetKey;
    
    float MaxAngle;
    UBTServer_FindTargetInFront();
};
