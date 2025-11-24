#pragma once
#include "CoreMinimal.h"
#include "VanityMasterySave.h"
#include "VanityMasteryResult.generated.h"

USTRUCT(BlueprintType)
struct FVanityMasteryResult {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FVanityMasterySave Previous;
    
    FVanityMasterySave Current;
    int32 FashionitesRewarded;
    ROGUECORE_API FVanityMasteryResult();
};
