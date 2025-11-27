#include "AFlyingBug.h"
#include "Perception/AIPerceptionComponent.h"
#include "Components/AudioComponent.h"
#include "Components/SphereComponent.h"
#include "EnemyComponent.h"
#include "FrozenPawnImpactComponent.h"
#include "HitReactionComponent.h"
#include "Net/UnrealNetwork.h"
#include "OutlineComponent.h"
#include "PawnAlertComponent.h"
#include "PawnStatsComponent.h"

AAFlyingBug::AAFlyingBug(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {

}


void AAFlyingBug::SetRotateTarget(AActor* aTarget) {
}

void AAFlyingBug::SetExternallyControlled(bool isExternallyControlled) {
}

void AAFlyingBug::SetAttackStance(bool isAttackStance) {
}

void AAFlyingBug::PlayVoice() {
}

void AAFlyingBug::OnStartFalling() {
}

void AAFlyingBug::OnRep_AttackStance() {
}


void AAFlyingBug::OnFreezeImpact() {
}

void AAFlyingBug::OnBugDeath(UHealthComponentBase* Health) {
}

float AAFlyingBug::GetMidZpointFromCielingAndFloor(float& distanceFromCieling, float& distanceFromFloor) const {
    return 0.0f;
}

bool AAFlyingBug::GetIsInAttackStance() const {
    return false;
}

void AAFlyingBug::All_Ragdoll_Implementation(const FVector_NetQuantize& Location, const FVector_NetQuantize& Impulse, uint8 BoneIndex) {
}


void AAFlyingBug::AddImpulseAndRagdoll(UHealthComponent* Health, float damageAmount, const FDamageData& DamageData, const TArray<UDamageTag*>& DamageTags) {
}

void AAFlyingBug::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const {
    Super::GetLifetimeReplicatedProps(OutLifetimeProps);
    
    DOREPLIFETIME(AAFlyingBug, RotateTarget);
    DOREPLIFETIME(AAFlyingBug, AttackStance);
}


