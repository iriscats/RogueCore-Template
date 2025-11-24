#pragma once
#include "CoreMinimal.h"
#include "SeasonLevel.generated.h"

class UReward;
USTRUCT(BlueprintType)
struct FSeasonLevel {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UReward* Reward;
    
    UReward* specialReward;
    ROGUECORE_API FSeasonLevel();
};
