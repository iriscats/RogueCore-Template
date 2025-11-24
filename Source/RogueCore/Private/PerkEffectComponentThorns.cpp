#include "PerkEffectComponentThorns.h"

UPerkEffectComponentThorns::UPerkEffectComponentThorns(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->DamageClass = NULL;
    this->PhysicalDamageClass = NULL;
    this->CoolDown = 0.00f;
    this->ThornsSTE = NULL;
}

void UPerkEffectComponentThorns::OnHit(float Damage, const FDamageData& DamageData, bool anyHealthLost, UHealthComponentBase* HealthComponent) {
}


