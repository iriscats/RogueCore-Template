#include "TallboyAnimInstance.h"

UTallboyAnimInstance::UTallboyAnimInstance(const FObjectInitializer& ObjectInitializer)
    : Super(ObjectInitializer) {
    this->IsAiming = false;
}

float UTallboyAnimInstance::GetUpperBodyBlend() const {
    return 0.0f;
}


