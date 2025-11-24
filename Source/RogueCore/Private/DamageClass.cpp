#include "DamageClass.h"

UDamageClass::UDamageClass() {
    this->ResistanceStat = NULL;
    this->IndicatorImage = NULL;
    this->DamageShout = NULL;
    this->DefaultDamageImpulse = NULL;
    this->ElementType = NULL;
    this->RagdollScale = 1.00f;
    this->BypassesShield = false;
    this->IgnoreDifficultyScaling = false;
    this->AffectedByFriendlyFire = true;
    this->IgnoresWeakpointBonus = false;
    this->IgnoresArmorModifiers = false;
    this->AffectedByCriticalHits = true;
}


