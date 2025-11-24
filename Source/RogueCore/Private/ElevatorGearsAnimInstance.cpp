#include "ElevatorGearsAnimInstance.h"

UElevatorGearsAnimInstance::UElevatorGearsAnimInstance() {
    this->Velocity = 0.00f;
    this->MoveSpeed = 1400.00f;
    this->IsMoving = false;
}

void UElevatorGearsAnimInstance::SetIsMoving(bool Moving) {
}

bool UElevatorGearsAnimInstance::GetIsMoving() const {
    return false;
}


