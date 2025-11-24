#pragma once
#include "CoreMinimal.h"
#include "ClaimableRewardEntry.generated.h"

class UClaimableRewardEntryWidget;
class UObject;
class UReward;
USTRUCT(BlueprintType)
struct FClaimableRewardEntry {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FText Title;
    
    FText Text;
    TSoftObjectPtr<UObject> Image;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    TArray<UReward*> Rewards;
    TSoftClassPtr<UClaimableRewardEntryWidget> EntryWidgetOverride;
    ROGUECORE_API FClaimableRewardEntry();
};
