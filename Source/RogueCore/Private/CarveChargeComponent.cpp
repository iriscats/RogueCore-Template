#include "CarveChargeComponent.h"
#include "Net/UnrealNetwork.h"

UCarveChargeComponent::UCarveChargeComponent(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->Damage = NULL;
    this->BumpSound = NULL;
    this->IsTelegraphing = false;
    this->isCharging = false;
    this->IsStoppingEarly = false;
    this->TelegraphSound = NULL;
    this->BumpCollider = NULL;
    this->CarveLocation = NULL;
    this->CurrentSpeed = 0.00f;
    this->Target = NULL;
    this->ChargeSpeed = 0.00f;
    this->CarveRadius = 0.00f;
    this->CarveFrequency = 0.00f;
}

void UCarveChargeComponent::Unpause() {
}

void UCarveChargeComponent::RamPlayer(APlayerCharacter* Player) {
}

void UCarveChargeComponent::RamEnemy(AEnemyDeepPathfinderCharacter* Enemy) {
}

void UCarveChargeComponent::Pause() {
}

void UCarveChargeComponent::OnRep_IsTelegraphing() {
}

void UCarveChargeComponent::OnRep_IsCharging() {
}

void UCarveChargeComponent::OnRep_Curve() {
}

void UCarveChargeComponent::OnBumpCollisionBeginOverlap(UPrimitiveComponent* OverlappedComp, AActor* Other, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult) {
}

void UCarveChargeComponent::OnBump(AActor* OtherActor) {
}

void UCarveChargeComponent::All_PlayBumpSound_Implementation() {
}

void UCarveChargeComponent::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const {
    Super::GetLifetimeReplicatedProps(OutLifetimeProps);
    
    DOREPLIFETIME(UCarveChargeComponent, IsTelegraphing);
    DOREPLIFETIME(UCarveChargeComponent, isCharging);
    DOREPLIFETIME(UCarveChargeComponent, Curve);
    DOREPLIFETIME(UCarveChargeComponent, CurrentSpeed);
    DOREPLIFETIME(UCarveChargeComponent, ChargeSpeed);
    DOREPLIFETIME(UCarveChargeComponent, CarveRadius);
    DOREPLIFETIME(UCarveChargeComponent, CarveFrequency);
}


