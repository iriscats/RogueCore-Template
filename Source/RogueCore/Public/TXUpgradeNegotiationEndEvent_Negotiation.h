#pragma once
#include "CoreMinimal.h"
#include "TXUpgradeNegotiationEndEvent_Negotiation_Selection.h"
#include "TXUpgradeNegotiationEndEvent_Negotiation.generated.h"

USTRUCT(BlueprintType)
struct FTXUpgradeNegotiationEndEvent_Negotiation {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 negotiation_index;
    
    FTXUpgradeNegotiationEndEvent_Negotiation_Selection Selection;
    int32 decision_time;
    int32 selection_order_position;
    ROGUECORE_API FTXUpgradeNegotiationEndEvent_Negotiation();
};
