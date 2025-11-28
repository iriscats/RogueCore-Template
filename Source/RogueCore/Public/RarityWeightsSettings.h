#pragma once
#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "LevelRarityWeights.h"
#include "RarityWeightsSettings.generated.h"

UCLASS(Blueprintable)
class URarityWeightsSettings : public UPrimaryDataAsset {
    GENERATED_BODY()
    

public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FLevelRarityWeights> RarityLevels;
    
    URarityWeightsSettings();
};
