#include "PerkEffectComponentShieldLink.h"

UPerkEffectComponentShieldLink::UPerkEffectComponentShieldLink(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->BoostedStatusEffect = NULL;
    this->BoostedStatusEffectInstance = NULL;
    this->LinkDistance = 300.00f;
    this->LinkStatusEffect = NULL;
}

void UPerkEffectComponentShieldLink::TimerFunction() {
}


