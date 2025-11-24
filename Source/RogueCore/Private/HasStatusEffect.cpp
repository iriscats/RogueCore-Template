#include "HasStatusEffect.h"

UHasStatusEffect::UHasStatusEffect() {
    this->StatusEffect = NULL;
    this->Mode = EStatusEffectStackMode::HasAnyStacks;
    this->count = 0;
}


