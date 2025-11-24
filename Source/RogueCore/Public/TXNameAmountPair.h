#pragma once
#include "CoreMinimal.h"
#include "TXNameAmountPair.generated.h"

USTRUCT(BlueprintType)
struct FTXNameAmountPair {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FString Name;
    
    int32 amount;
    ROGUECORE_API FTXNameAmountPair();
};
