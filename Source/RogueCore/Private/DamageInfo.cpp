#include "DamageInfo.h"

FDamageInfo::FDamageInfo() {
    this->DamageInflicted = 0.00f;
    this->BaseDamage = 0.00f;
    this->Critical = false;
    this->Weakpoint = false;
    this->Radial = false;
    this->RadialRange = 0.00f;
    this->KillingBlow = false;
}

