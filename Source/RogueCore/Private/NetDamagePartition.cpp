#include "NetDamagePartition.h"

FNetDamagePartition::FNetDamagePartition() {
    this->DamageVector = EDamageVector::Ranged;
    this->Type = NULL;
    this->amount = 0.00f;
    this->FearChance = 0.00f;
    this->StaggerChance = 0.00f;
}

