#pragma once
#include "CoreMinimal.h"
#include "TXUnlockUpgrade.generated.h"

USTRUCT(BlueprintType)
struct FTXUnlockUpgrade {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FString Name;
    
    ROGUECORE_API FTXUnlockUpgrade();
};
