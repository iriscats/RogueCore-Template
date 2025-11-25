#pragma once
#include "CoreMinimal.h"
#include "MilestoneTier.generated.h"

USTRUCT(BlueprintType)
struct FMilestoneTier {
    GENERATED_BODY()
    // UPROPERTY fields moved from protected section

public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float CompletionCount;
    
    int32 PerkPoints;
    ROGUECORE_API FMilestoneTier();
};
