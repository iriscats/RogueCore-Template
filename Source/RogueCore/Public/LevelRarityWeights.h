#pragma once
#include "CoreMinimal.h"
#include "RarityWeightItem.h"
#include "LevelRarityWeights.generated.h"

USTRUCT(BlueprintType)
struct FLevelRarityWeights {
    GENERATED_BODY()
    // UPROPERTY fields moved from protected section

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))

    TArray<FRarityWeightItem> RarityLevelItems;

    

    ROGUECORE_API FLevelRarityWeights();



public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FRarityWeightItem> RarityLevelItems;
    
    ROGUECORE_API FLevelRarityWeights();
};
