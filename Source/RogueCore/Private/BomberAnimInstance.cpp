#include "BomberAnimInstance.h"

UBomberAnimInstance::UBomberAnimInstance(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->ShouldBomb = false;
    this->ShouldSpiral = false;
    this->IsBombing = false;
    this->IsSpiraling = false;
}


