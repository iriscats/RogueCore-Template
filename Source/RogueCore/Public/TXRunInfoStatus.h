#pragma once
#include "CoreMinimal.h"
#include "TXRunInfoStatus.generated.h"

USTRUCT(BlueprintType)
struct FTXRunInfoStatus {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FString run_name;
    
    int32 run_depth;
    int32 run_seed;
    ROGUECORE_API FTXRunInfoStatus();
};
