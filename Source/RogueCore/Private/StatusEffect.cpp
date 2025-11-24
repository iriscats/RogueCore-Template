#include "StatusEffect.h"
#include "Templates/SubclassOf.h"

UStatusEffect::UStatusEffect() {
    this->DurationModifier = NULL;
    this->PawnAffliction = NULL;
    this->MaxResistance = 1.00f;
    this->DamageClass = NULL;
    this->ExclusiveKey = NULL;
    this->PopSetting = EStatusEffectPopSetting::Temporary;
    this->TriggerTwiceOnPush = false;
    this->CanStack = false;
    this->MaxStack = 10;
    this->RemoveAllStacksAfterDuration = false;
    this->Duration = -1.00f;
    this->RestartDurationOnApply = true;
    this->ApplyDurationAfterPop = false;
    this->RemoveOnDeath = true;
    this->RemoveOnTemperatureStateChange = false;
    this->AllowExternalSread = false;
    this->RefreshDurationOnApplication = false;
    this->OnlyOneInstanceUpdates = false;
}

float UStatusEffect::GetStatusEffectDuration(TSubclassOf<UStatusEffect> StatusEffect) {
    return 0.0f;
}

UStatusEffectItem* UStatusEffect::GetFirstStatusEffectItem(TSubclassOf<UStatusEffectItem> itemClass, bool assertOnFail) const {
    return NULL;
}

bool UStatusEffect::CanTrigger(AActor* Target) const {
    return false;
}


