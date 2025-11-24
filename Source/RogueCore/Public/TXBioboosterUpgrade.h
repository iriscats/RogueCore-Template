#pragma once
#include "CoreMinimal.h"
#include "TXBioboosterUpgrade.generated.h"

USTRUCT(BlueprintType)
struct FTXBioboosterUpgrade {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FString Name;
    
    ROGUECORE_API FTXBioboosterUpgrade();
};
