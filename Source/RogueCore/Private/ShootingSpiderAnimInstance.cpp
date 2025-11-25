#include "ShootingSpiderAnimInstance.h"

UShootingSpiderAnimInstance::UShootingSpiderAnimInstance(const FObjectInitializer& ObjectInitializer)
    : Super(ObjectInitializer)
{
    this->LookAtBlend = 0.00f;
    this->CheckCurve = true;
}


