#pragma once
#include "CoreMinimal.h"
#include "TXNegotiationUpgrade.generated.h"

USTRUCT(BlueprintType)
struct FTXNegotiationUpgrade {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FString Name;
    
    ROGUECORE_API FTXNegotiationUpgrade();
};
