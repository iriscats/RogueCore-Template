#pragma once
#include "CoreMinimal.h"
#include "TXArtifactNegotiationEndEvent_Negotiation_Selection_Options.h"
#include "TXArtifactNegotiationEndEvent_Negotiation_Selection.generated.h"

USTRUCT(BlueprintType)
struct FTXArtifactNegotiationEndEvent_Negotiation_Selection {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FTXArtifactNegotiationEndEvent_Negotiation_Selection_Options> Options;
    
    FString requested;
    FString Selected;
    bool was_select_contested;
    ROGUECORE_API FTXArtifactNegotiationEndEvent_Negotiation_Selection();
};
