#pragma once
#include "CoreMinimal.h"
#include "TXUpgradeNegotiationEndEvent_Negotiation_Selection_Options.h"
#include "TXUpgradeNegotiationEndEvent_Negotiation_Selection.generated.h"

USTRUCT(BlueprintType)
struct FTXUpgradeNegotiationEndEvent_Negotiation_Selection {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FTXUpgradeNegotiationEndEvent_Negotiation_Selection_Options> Options;
    
    FString requested;
    FString Selected;
    bool was_select_contested;
    ROGUECORE_API FTXUpgradeNegotiationEndEvent_Negotiation_Selection();
};
