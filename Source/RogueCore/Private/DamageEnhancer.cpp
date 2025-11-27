#include "DamageEnhancer.h"
#include "Components/BoxComponent.h"
#include "Components/SphereComponent.h"
#include "Components/StaticMeshComponent.h"
#include "CapsuleHitscanComponent.h"
#include "DamageComponent.h"
#include "HealthComponent.h"
#include "HitscanComponent.h"
#include "ReflectionHitscanComponent.h"

ADamageEnhancer::ADamageEnhancer(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {

}

void ADamageEnhancer::HitByHitScan(UHitscanBaseComponent* Component, const FVector& Origin, const FHitResult& HitResult) {
}

void ADamageEnhancer::Client_CompleteTrace_Implementation(const FEnhancedTrace& trace) {
}

void ADamageEnhancer::BeginOverlapVsProjectile(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult) {
}

void ADamageEnhancer::All_PasteHitScanComponent_Implementation(UHitscanBaseComponent* HitScan) {
}

void ADamageEnhancer::All_PasteDamageComponent_Implementation(UDamageComponent* Damage) {
}


