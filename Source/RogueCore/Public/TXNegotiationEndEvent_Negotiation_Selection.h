#pragma once
#include "CoreMinimal.h"
#include "TXNegotiationEndEvent_Negotiation_Selection_Options.h"
#include "TXNegotiationEndEvent_Negotiation_Selection.generated.h"

USTRUCT(BlueprintType)
struct FTXNegotiationEndEvent_Negotiation_Selection {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FTXNegotiationEndEvent_Negotiation_Selection_Options> Options;
    
    FString requested;
    FString Selected;
    bool skipped;
    ROGUECORE_API FTXNegotiationEndEvent_Negotiation_Selection();
};
