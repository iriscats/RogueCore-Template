#pragma once
#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "BXEProgressionLevel.h"
#include "RarityWeightsSelection.h"
#include "BXEProgressionSettings.generated.h"

class UBXEInventoryList;
class UBXEUnlockCollection;
class UUnlockCollectionTag;
UCLASS(Blueprintable)
class UBXEProgressionSettings : public UDataAsset {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UBXEInventoryList* StartInventory;
    
    TArray<FBXEProgressionLevel> Levels;
    UBXEUnlockCollection* SoloDroneCollection;
protected:
    TArray<UUnlockCollectionTag*> CollectionTags;
    FRarityWeightsSelection RarityWeights;
    UBXEProgressionSettings();
};
