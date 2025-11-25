#include "FacilityTentacleHeadAnimInstance.h"

UFacilityTentacleHeadAnimInstance::UFacilityTentacleHeadAnimInstance(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->Searching = false;
    this->Melee = false;
    this->RangedAttack = false;
}


