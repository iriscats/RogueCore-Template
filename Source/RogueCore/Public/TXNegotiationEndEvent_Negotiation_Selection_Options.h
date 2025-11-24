#pragma once
#include "CoreMinimal.h"
#include "TXNegotiationEndEvent_Negotiation_Selection_Options.generated.h"

USTRUCT(BlueprintType)
struct FTXNegotiationEndEvent_Negotiation_Selection_Options {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FString Name;
    
    FString Rarity;
    ROGUECORE_API FTXNegotiationEndEvent_Negotiation_Selection_Options();
};
