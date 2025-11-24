#include "RewardTreeFunctionLibrary.h"

URewardTreeFunctionLibrary::URewardTreeFunctionLibrary() {
}

bool URewardTreeFunctionLibrary::IsNodeUnlocked(UObject* WorldContext, int32 RewardTreeNodeID) {
    return false;
}

bool URewardTreeFunctionLibrary::IsNodeBought(UObject* WorldContext, int32 RewardTreeNodeID) {
    return false;
}

bool URewardTreeFunctionLibrary::IsNodeBehindLock(UObject* WorldContext, int32 RewardTreeNodeID) {
    return false;
}

bool URewardTreeFunctionLibrary::BuyTreeNode(UObject* WorldContextObject, AFSDPlayerController* Player, int32 RewardTreeNodeID) {
    return false;
}


