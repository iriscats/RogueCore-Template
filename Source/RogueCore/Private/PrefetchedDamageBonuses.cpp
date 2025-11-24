#include "PrefetchedDamageBonuses.h"

UPrefetchedDamageBonuses::UPrefetchedDamageBonuses(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->DamageAsset = NULL;
}

FPrefetchedDamageBonusResult UPrefetchedDamageBonuses::GetResult() const {
    return FPrefetchedDamageBonusResult{};
}


