#include "AddDamageBonusStatusEffectItem.h"

UAddDamageBonusStatusEffectItem::UAddDamageBonusStatusEffectItem() {
    this->DamageBonus = NULL;
    this->Value = 0.00f;
    this->Mode = EDamagebonusMode::Numerical;
    this->BonusType = EDamageUpgrade::Damage;
    this->ApplicationType = EDamageBonusApplicationType::OnTarget;
}


