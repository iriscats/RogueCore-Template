#pragma once
#include "CoreMinimal.h"
#include "TXArtifactNegotiationEndEvent_Negotiation_Selection.h"
#include "TXArtifactNegotiationEndEvent_Negotiation.generated.h"

USTRUCT(BlueprintType)
struct FTXArtifactNegotiationEndEvent_Negotiation {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 negotiation_index;
    
    FTXArtifactNegotiationEndEvent_Negotiation_Selection Selection;
    int32 decision_time;
    int32 selection_order_position;
    ROGUECORE_API FTXArtifactNegotiationEndEvent_Negotiation();
};
