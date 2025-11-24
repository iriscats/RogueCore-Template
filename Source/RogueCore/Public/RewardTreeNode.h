#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "RewardTreeNode.generated.h"

class UReward;
USTRUCT(BlueprintType)
struct FRewardTreeNode {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UReward* Reward;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 Cost;
    int32 NodeID;
    TArray<int32> ConnectedNodes;
    bool bIsBig;
    bool bIsStartingNode;
    FVector2D position;
    ROGUECORE_API FRewardTreeNode();
};
