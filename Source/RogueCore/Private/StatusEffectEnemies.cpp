#include "StatusEffectEnemies.h"

UStatusEffectEnemies::UStatusEffectEnemies() {
    this->ChanceToApply = 1.00f;
    this->OverrideReplacesDefault = true;
}

void UStatusEffectEnemies::OnEnemySpawned(APawn* Enemy, UEnemyDescriptor* descriptor) {
}


