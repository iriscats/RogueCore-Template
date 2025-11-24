#include "DamageListenerData.h"

FDamageListenerData::FDamageListenerData() {
    this->DamageVector = EDamageVector::Ranged;
    this->DamagType = NULL;
    this->Target = NULL;
    this->ArmorDamage = 0.00f;
    this->DamageDealt = 0.00f;
    this->DamgeMultiplier = 0.00f;
    this->KillingBlow = false;
    this->Radial = false;
}

