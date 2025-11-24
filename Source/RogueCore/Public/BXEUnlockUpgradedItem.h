#pragma once
#include "CoreMinimal.h"
#include "BXEUniqueUpgradeSet.h"
#include "BXEUnlockItem.h"
#include "BXEWeightedWeaponUpgrades.h"
#include "BXEUnlockUpgradedItem.generated.h"

class UItemUpgrade;
UCLASS(Blueprintable)
class UBXEUnlockUpgradedItem : public UBXEUnlockItem {
    GENERATED_BODY()
    // UPROPERTY fields moved from protected section

public:

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<TSoftObjectPtr<UItemUpgrade>> AlwaysAppliedUpgrades;
    
    TArray<FBXEWeightedWeaponUpgrades> upgrades;
    TArray<FBXEUniqueUpgradeSet> UniqueUpgrades;
    bool UseReducedAttributeAmount;
    UBXEUnlockUpgradedItem();
    UFUNCTION(BlueprintCallable)
    TArray<UItemUpgrade*> Cheat_GetUpgrades();
};
