#include "SharkEnemy.h"
#include "Components/SphereComponent.h"
#include "NiagaraComponent.h"
#include "DamageComponent.h"
#include "EnemyComponent.h"
#include "FakePhysGrabberComponent.h"
#include "InDangerComponent.h"
#include "Net/UnrealNetwork.h"

ASharkEnemy::ASharkEnemy(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {

}

void ASharkEnemy::SetVulnerable() {
}

void ASharkEnemy::ReleasePlayer(AActor* playerchar, bool fullGrabElapsed) {
}

void ASharkEnemy::PopRecentlyBumpedPlayer() {
}


void ASharkEnemy::OnSeePawn(APawn* aPawn) {
}

void ASharkEnemy::OnRep_State(ESharkEnemyState oldState) {
}

void ASharkEnemy::OnRep_DiveTime() {
}

void ASharkEnemy::OnNearTarget(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult) {
}



void ASharkEnemy::OnHit(float HitDamage, const FDamageData& DamageData, bool anyHealthLost, UHealthComponentBase* InHealthComponent) {
}



void ASharkEnemy::OnDeathDetailed(UHealthComponent* aHealthComponent, float damageAmount, const FDamageData& DamageData, const TArray<UDamageTag*>& dTags) {
}

void ASharkEnemy::OnCollided(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult) {
}

void ASharkEnemy::Jumped_Implementation() {
}

void ASharkEnemy::ImpactSound_Implementation() {
}

void ASharkEnemy::DiveShow() {
}

void ASharkEnemy::DiveHide() {
}

void ASharkEnemy::All_DoRagdollImpact_Implementation(const FVector_NetQuantize& Direction) {
}

void ASharkEnemy::ActivateDanger() {
}

void ASharkEnemy::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const {
    Super::GetLifetimeReplicatedProps(OutLifetimeProps);
    
    DOREPLIFETIME(ASharkEnemy, DiveForSeconds);
    DOREPLIFETIME(ASharkEnemy, State);
}


