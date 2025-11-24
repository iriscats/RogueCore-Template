#include "PerkEffectComponentSalute.h"

UPerkEffectComponentSalute::UPerkEffectComponentSalute(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->CoolDown = 60.00f;
    this->FleeRadius = 400.00f;
}

void UPerkEffectComponentSalute::OnSalute() {
}


