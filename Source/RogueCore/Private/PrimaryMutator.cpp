#include "PrimaryMutator.h"

UPrimaryMutator::UPrimaryMutator() {
    this->StageLogic = NULL;
    this->HazardBonus = 0.00f;
    this->ShowInUserInterface = true;
    this->Icon = NULL;
}

TArray<URiskVector*> UPrimaryMutator::GetRiskVectors() {
    return TArray<URiskVector*>();
}

TArray<UMutator*> UPrimaryMutator::GetMutators() {
    return TArray<UMutator*>();
}


