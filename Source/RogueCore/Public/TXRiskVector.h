#pragma once
#include "CoreMinimal.h"
#include "TXRiskVector.generated.h"

USTRUCT(BlueprintType)
struct FTXRiskVector {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FString Name;
    
    ROGUECORE_API FTXRiskVector();
};
