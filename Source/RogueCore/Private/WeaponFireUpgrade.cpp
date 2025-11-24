#include "WeaponFireUpgrade.h"
#include "Templates/SubclassOf.h"

UWeaponFireUpgrade::UWeaponFireUpgrade() {
    this->upgradeType = EWeaponFireUpgradeType::MaxVerticalSpread;
}

FUpgradeValues UWeaponFireUpgrade::GetUpgradedValue(TSubclassOf<AItem> Item, AFSDPlayerState* Player, EWeaponFireUpgradeType NewUpgradeType) {
    return FUpgradeValues{};
}


