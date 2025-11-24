#pragma once
#include "CoreMinimal.h"
#include "ERarityWeightType.h"
#include "RarityWeightsSelection.generated.h"

class URarityWeightsSettings;
USTRUCT(BlueprintType)
struct FRarityWeightsSelection {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    URarityWeightsSettings* DefaultRarityWeights;

    TMap<ERarityWeightType, URarityWeightsSettings*> TypeRarityWeights;
    ROGUECORE_API FRarityWeightsSelection();
};
