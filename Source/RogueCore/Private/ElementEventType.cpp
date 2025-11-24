#include "ElementEventType.h"

UElementEventType::UElementEventType() {
    this->OnActivateSoundCue = NULL;
    this->OnDeactivateSoundCue = NULL;
    this->OnActivateParticleSystem = NULL;
    this->OnDeactivateParticleSystem = NULL;
    this->DamageBonus = 0.00f;
    this->PlayerOverrideSetup = false;
}


