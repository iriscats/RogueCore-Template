#include "DamageData.h"

FDamageData::FDamageData() {
    this->DamageVector = EDamageVector::Ranged;
    this->DamageClass = NULL;
    this->DamageModifier = 0.00f;
    this->ArmorPenetration = 0.00f;
}

