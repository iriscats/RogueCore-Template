#pragma once
#include "CoreMinimal.h"

#include "RewardTreeLock.h"
#include "RewardTreeNode.h"
#include "SavableDataAsset.h"
#include "RewardTree.generated.h"

class UReward;
UCLASS(Blueprintable, EditInlineNew)
class URewardTree : public USavableDataAsset {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FRewardTreeNode> Nodes;
    
    TArray<FRewardTreeLock> Locks;
    TMap<int32, int32> NodeIDToArrayIndex;
    URewardTree();
    UFUNCTION(BlueprintCallable)
    void ClearNodes();
    void AddNode(UReward* Reward, int32 Cost, int32 NodeID, TArray<int32> ConnectedNodes, bool isStartingNode, bool isBig, FVector2D position);
    void AddLock(int32 RequiredForUnlock, FVector2D position);
};
