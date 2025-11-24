#include "ClientDamageRapport.h"

FClientDamageRapport::FClientDamageRapport() {
    this->HitComponent = NULL;
    this->PhysMat = NULL;
    this->DamageCauser = NULL;
    this->Instigator = NULL;
    this->Target = NULL;
    this->BoneIndex = 0;
    this->BaseDamage = 0.00f;
    this->CritLevel = 0;
}

