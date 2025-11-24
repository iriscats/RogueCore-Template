#include "WeaponOverviewAttributeEntryData.h"

FWeaponOverviewAttributeEntryData::FWeaponOverviewAttributeEntryData() {
    this->amount = 0.00f;
    this->Unit = EWeaponOverviewUnitType::Numerical;
    this->ModifierType = EWeaponOverviewModifierType::Additive;
    this->IsHidden = false;
}

