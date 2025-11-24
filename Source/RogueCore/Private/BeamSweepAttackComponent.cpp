#include "BeamSweepAttackComponent.h"

UBeamSweepAttackComponent::UBeamSweepAttackComponent(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->HotRockMaterial = NULL;
    this->SweepDuration = 1.00f;
    this->SweepAngle = 20.00f;
    this->InflictedStatusEffect = NULL;
    this->CarveFrequency = 10.00f;
    this->IsAttacking = false;
    this->TraceChannel = TraceTypeQuery1;
    this->TargetedActor = NULL;
}

void UBeamSweepAttackComponent::StopAttackMulticast_Implementation() {
}

void UBeamSweepAttackComponent::StartAttackMulticast_Implementation(FVector sweepStartDirection, FVector sweepEndDirection) {
}


