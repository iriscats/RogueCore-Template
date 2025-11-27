#include "BasicThrowableItem.h"
#include "Components/BoxComponent.h"
#include "Components/SphereComponent.h"
#include "Components/StaticMeshComponent.h"
#include "CarriableComponent.h"
#include "FirstPersonStaticMeshComponent.h"
#include "InstantUsable.h"

ABasicThrowableItem::ABasicThrowableItem(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {

}

void ABasicThrowableItem::ResetImpactSound() {
}

void ABasicThrowableItem::OnUsed(APlayerCharacter* User, EInputKeys Key) {
}

void ABasicThrowableItem::OnUsableChanged(bool CanUse) {
}

void ABasicThrowableItem::OnPickedUp() {
}

void ABasicThrowableItem::OnDropped() {
}

void ABasicThrowableItem::OnComponentHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit) {
}


