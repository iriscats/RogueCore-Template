#include "PatrolBot.h"
#include "Components/AudioComponent.h"
#include "Particles/ParticleSystemComponent.h"
#include "Components/SphereComponent.h"
#include "NiagaraComponent.h"
#include "AvoidCeilingComponent.h"
#include "DamageComponent.h"
#include "EnemyComponent.h"
#include "HackingUsableComponent.h"
#include "Net/UnrealNetwork.h"
#include "PawnAlertComponent.h"
#include "PlayerImpactCooldownComponent.h"
#include "ProjectileAttackComponent.h"

APatrolBot::APatrolBot(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {

}

void APatrolBot::SetIsPatrolling(bool patroling) {
}

void APatrolBot::SetHacked() {
}

void APatrolBot::SetFiringRockets(bool firing) {
}

void APatrolBot::ReviveDrone() {
}





void APatrolBot::OnRep_State() {
}

void APatrolBot::OnRep_IsLockedOn() {
}

void APatrolBot::OnRep_FiringRockets() {
}

void APatrolBot::OnRep_ControlState(EPatrolBotControlState oldState) {
}


void APatrolBot::OnMovementStateChanged(EDeepMovementState NewState) {
}






void APatrolBot::OnDroneAlerted() {
}



void APatrolBot::OnCollided(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult) {
}

void APatrolBot::Jumped_Implementation() {
}

bool APatrolBot::IsHacked() const {
    return false;
}

void APatrolBot::ImpactSound_Implementation() {
}

void APatrolBot::EndFireRockets() {
}

void APatrolBot::DisableDrone() {
}

void APatrolBot::All_SetLaserBeamActive_Implementation(bool Active) {
}

void APatrolBot::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const {
    Super::GetLifetimeReplicatedProps(OutLifetimeProps);
    
    DOREPLIFETIME(APatrolBot, IsLockedOn);
    DOREPLIFETIME(APatrolBot, State);
    DOREPLIFETIME(APatrolBot, ControlState);
    DOREPLIFETIME(APatrolBot, FiringRockets);
    DOREPLIFETIME(APatrolBot, Alerted);
    DOREPLIFETIME(APatrolBot, CurrentTarget);
}


