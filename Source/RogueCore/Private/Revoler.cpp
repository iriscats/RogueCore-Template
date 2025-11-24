#include "Revoler.h"
#include "DamageComponent.h"

ARevoler::ARevoler(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->DamageComponent = CreateDefaultSubobject<UDamageComponent>(TEXT("DamageComponent"));
    this->OnKillFearFactor = 0.00f;
    this->OnKillFearRange = 500.00f;
}

void ARevoler::OnTargetKilled(AActor* Target, UFSDPhysicalMaterial* PhysMat, bool wasDirectHit) {
}


