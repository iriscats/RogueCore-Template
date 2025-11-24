#pragma once
#include "CoreMinimal.h"
#include "ELockOnWeaponUpgrades.h"
#include "StandardItemUpgrade.h"
#include "Templates/SubclassOf.h"
#include "UpgradeValues.h"
#include "LockOnWeaponUpgrade.generated.h"

class AFSDPlayerState;
class AItem;
UCLASS(Blueprintable, EditInlineNew, MinimalAPI)
class ULockOnWeaponUpgrade : public UStandardItemUpgrade {
    GENERATED_BODY()
    // UPROPERTY fields moved from protected section

public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    ELockOnWeaponUpgrades upgradeType;
    
    ULockOnWeaponUpgrade();
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static FUpgradeValues GetUpgradedValue(TSubclassOf<AItem> Item, AFSDPlayerState* Player, ELockOnWeaponUpgrades NewUpgradeType);
};
