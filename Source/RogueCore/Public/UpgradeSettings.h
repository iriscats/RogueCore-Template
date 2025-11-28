#pragma once
#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "UpgradeCostItem.h"
#include "UpgradeSettings.generated.h"

UCLASS(Blueprintable)
class UUpgradeSettings : public UDataAsset {
    GENERATED_BODY()
    
public:

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<int32> ClassAUpgradeCosts;
    
    TArray<int32> ClassBUpgradeCosts;
    TArray<int32> GearAUpgradeCosts;
    TArray<int32> GearBUpgradeCosts;
    TArray<int32> ArmorUpgradeCosts;
    TArray<int32> PickaxeUpgradeCosts;
    TArray<int32> ClassBoscoUpgradeCosts;
    TArray<FUpgradeCostItem> ClassAResourceCosts;
    TArray<FUpgradeCostItem> ClassBResourceCosts;
    TArray<FUpgradeCostItem> GearAResourceCosts;
    TArray<FUpgradeCostItem> GearBResourceCosts;
    TArray<FUpgradeCostItem> ArmorResourceCosts;
    TArray<FUpgradeCostItem> PickaxeResourceCosts;
    TArray<FUpgradeCostItem> ClassBoscoResourceCosts;
    UUpgradeSettings();
};
