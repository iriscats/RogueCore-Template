#pragma once
#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "RewardTreeFunctionLibrary.generated.h"

class AFSDPlayerController;
class UObject;
UCLASS(Blueprintable)
class URewardTreeFunctionLibrary : public UBlueprintFunctionLibrary {
    GENERATED_BODY()
public:
    URewardTreeFunctionLibrary();
    UFUNCTION(BlueprintCallable, BlueprintPure, meta=(WorldContext="WorldContext"))
    static bool IsNodeUnlocked(UObject* WorldContext, int32 RewardTreeNodeID);
    
    static bool IsNodeBought(UObject* WorldContext, int32 RewardTreeNodeID);
    static bool IsNodeBehindLock(UObject* WorldContext, int32 RewardTreeNodeID);
    UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContextObject"))
    static bool BuyTreeNode(UObject* WorldContextObject, AFSDPlayerController* Player, int32 RewardTreeNodeID);
};
