#pragma once
#include "CoreMinimal.h"
#include "BehaviorTree/BTDecorator.h"
#include "BehaviorTree/BehaviorTreeTypes.h"
#include "BTDecorator_CheckNearbyPlayers.generated.h"

UCLASS(Blueprintable)
class ROGUECORE_API UBTDecorator_CheckNearbyPlayers : public UBTDecorator {
    GENERATED_BODY()
    
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float Range;
    
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    uint32 NumberOfPlayers;
    bool IncludeTarget;
    FBlackboardKeySelector TargetKey;
    UBTDecorator_CheckNearbyPlayers();
};
