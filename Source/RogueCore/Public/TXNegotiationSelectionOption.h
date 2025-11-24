#pragma once
#include "CoreMinimal.h"
#include "TXNegotiationUpgrade.h"
#include "TXNegotiationSelectionOption.generated.h"

USTRUCT(BlueprintType)
struct FTXNegotiationSelectionOption {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FString Name;
    
    FString Rarity;
    TArray<FTXNegotiationUpgrade> upgrades;
    ROGUECORE_API FTXNegotiationSelectionOption();
};
