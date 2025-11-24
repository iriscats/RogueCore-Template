#pragma once
#include "CoreMinimal.h"
#include "TXNegotiationEndEvent_Loadout_Items.generated.h"

USTRUCT(BlueprintType)
struct FTXNegotiationEndEvent_Loadout_Items {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FString item_name;
    
    FString Slot;
    FString Rarity;
    TArray<FString> item_upgrades;
    ROGUECORE_API FTXNegotiationEndEvent_Loadout_Items();
};
