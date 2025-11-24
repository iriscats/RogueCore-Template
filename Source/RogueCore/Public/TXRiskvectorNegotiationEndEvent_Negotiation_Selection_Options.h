#pragma once
#include "CoreMinimal.h"
#include "TXRiskvectorNegotiationEndEvent_Negotiation_Selection_Options.generated.h"

USTRUCT(BlueprintType)
struct FTXRiskvectorNegotiationEndEvent_Negotiation_Selection_Options {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FString positive;
    
    FString negative;
    int32 vote_amount;
    ROGUECORE_API FTXRiskvectorNegotiationEndEvent_Negotiation_Selection_Options();
};
