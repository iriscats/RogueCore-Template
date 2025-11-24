#pragma once
#include "CoreMinimal.h"
#include "TXPlayerEnhancement.generated.h"

USTRUCT(BlueprintType)
struct FTXPlayerEnhancement {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FString Name;
    
    ROGUECORE_API FTXPlayerEnhancement();
};
