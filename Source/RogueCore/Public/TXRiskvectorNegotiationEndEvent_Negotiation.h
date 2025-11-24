#pragma once
#include "CoreMinimal.h"
#include "TXRiskvectorNegotiationEndEvent_Negotiation_Selection.h"
#include "TXRiskvectorNegotiationEndEvent_Negotiation.generated.h"

USTRUCT(BlueprintType)
struct FTXRiskvectorNegotiationEndEvent_Negotiation {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 negotiation_index;
    
    FTXRiskvectorNegotiationEndEvent_Negotiation_Selection Selection;
    int32 decision_time;
    int32 selection_order_position;
    ROGUECORE_API FTXRiskvectorNegotiationEndEvent_Negotiation();
};
