#pragma once
#include "CoreMinimal.h"
#include "TXRiskvectorNegotiationEndEvent_Negotiation_Selection_Options.h"
#include "TXRiskvectorNegotiationEndEvent_Negotiation_Selection.generated.h"

USTRUCT(BlueprintType)
struct FTXRiskvectorNegotiationEndEvent_Negotiation_Selection {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FTXRiskvectorNegotiationEndEvent_Negotiation_Selection_Options> Options;
    
    FString voted_for;
    int32 Selected;
    ROGUECORE_API FTXRiskvectorNegotiationEndEvent_Negotiation_Selection();
};
