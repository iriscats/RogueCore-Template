#pragma once
#include "CoreMinimal.h"
#include "TXUpgradeNegotiationEndEvent_Negotiation_Selection_Options.generated.h"

USTRUCT(BlueprintType)
struct FTXUpgradeNegotiationEndEvent_Negotiation_Selection_Options {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FString Name;
    
    FString Rarity;
    ROGUECORE_API FTXUpgradeNegotiationEndEvent_Negotiation_Selection_Options();
};
