#pragma once
#include "CoreMinimal.h"
#include "BXEWeightedWeaponUpgrades.h"
#include "BXEUniqueUpgradeSet.generated.h"

USTRUCT(BlueprintType)
struct FBXEUniqueUpgradeSet {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSet<FBXEWeightedWeaponUpgrades> UpgradeSet;
    
    ROGUECORE_API FBXEUniqueUpgradeSet();
};
