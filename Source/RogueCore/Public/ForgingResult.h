#pragma once
#include "CoreMinimal.h"
#include "ForgingResult.generated.h"

USTRUCT(BlueprintType)
struct FForgingResult {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool LevelledUp;
    
    int32 RewardLevel;
    int32 RewardSeed;
    ROGUECORE_API FForgingResult();
};
