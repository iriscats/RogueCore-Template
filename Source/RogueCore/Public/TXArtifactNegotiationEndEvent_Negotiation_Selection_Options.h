#pragma once
#include "CoreMinimal.h"
#include "TXArtifactNegotiationEndEvent_Negotiation_Selection_Options.generated.h"

USTRUCT(BlueprintType)
struct FTXArtifactNegotiationEndEvent_Negotiation_Selection_Options {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FString Name;
    
    ROGUECORE_API FTXArtifactNegotiationEndEvent_Negotiation_Selection_Options();
};
