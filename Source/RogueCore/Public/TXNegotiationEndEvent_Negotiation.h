#pragma once
#include "CoreMinimal.h"
#include "TXNegotiationEndEvent_Negotiation_Selection.h"
#include "TXNegotiationEndEvent_Negotiation.generated.h"

USTRUCT(BlueprintType)
struct FTXNegotiationEndEvent_Negotiation {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FTXNegotiationEndEvent_Negotiation_Selection Selection;
    
    int32 decision_time;
    FString negotiation_type;
    int32 selection_order;
    ROGUECORE_API FTXNegotiationEndEvent_Negotiation();
};
