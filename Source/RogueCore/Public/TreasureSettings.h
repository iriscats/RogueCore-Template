#pragma once
#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "TreasureSettings.generated.h"

class UItemAquisitionSource;
UCLASS(Blueprintable)
class UTreasureSettings : public UDataAsset {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UItemAquisitionSource* CrateAquisitionSource;
    
    UItemAquisitionSource* LostPackAquisitionSource;
    UItemAquisitionSource* VanityChestAquisitionSource;
    UTreasureSettings();
};
