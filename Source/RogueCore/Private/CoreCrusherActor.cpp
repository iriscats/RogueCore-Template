#include "CoreCrusherActor.h"
#include "Components/SceneComponent.h"
#include "Components/SkeletalMeshComponent.h"
#include "Components/SphereComponent.h"
#include "FriendlyHealthComponent.h"
#include "Net/UnrealNetwork.h"
#include "PathfinderCollisionComponent.h"
#include "RepairableComponent.h"
#include "RepairableUsable.h"
#include "SingleUsableComponent.h"

ACoreCrusherActor::ACoreCrusherActor(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {

}

void ACoreCrusherActor::RepairableUsableOnUsedBy(APlayerCharacter* User, EInputKeys Key) {
}


void ACoreCrusherActor::OnRunningRepairUsedBy(APlayerCharacter* User, EInputKeys Key) {
}

void ACoreCrusherActor::OnRevivableUsedBy(APlayerCharacter* User, EInputKeys Key) {
}

void ACoreCrusherActor::OnRep_State() {
}

void ACoreCrusherActor::OnDeath(UHealthComponentBase* HealthComponent) {
}

void ACoreCrusherActor::OnDamage(float amount) {
}

void ACoreCrusherActor::OnAllResourcesAcquiredEvent(URepairableComponent* Component) {
}

void ACoreCrusherActor::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const {
    Super::GetLifetimeReplicatedProps(OutLifetimeProps);
    
    DOREPLIFETIME(ACoreCrusherActor, State);
    DOREPLIFETIME(ACoreCrusherActor, CurrentBootLeft);
}


