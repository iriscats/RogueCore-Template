#include "AbilitySpawnActor.h"

AAbilitySpawnActor::AAbilitySpawnActor(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->amount = 0.00f;
    this->Lifetime = -1.00f;
    this->Type = EAbilityAmountType::Damage;
}

