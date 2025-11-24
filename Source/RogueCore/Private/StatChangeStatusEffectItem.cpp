#include "StatChangeStatusEffectItem.h"

UStatChangeStatusEffectItem::UStatChangeStatusEffectItem() {
    this->Stat = NULL;
    this->StatChange = 0.00f;
    this->AffectedByResistances = false;
}

UStatusEffect* UStatChangeStatusEffectItem::CreateStatSTE(UObject* Owner, UPawnStat* PawnStat, float StartingValue) {
    return NULL;
}


