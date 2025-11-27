#include "PlagueCleanupItem.h"
#include "Components/BoxComponent.h"
#include "Components/SphereComponent.h"
#include "CrosshairAggregator.h"
#include "InstantUsable.h"
#include "KeepInsideWorld.h"

APlagueCleanupItem::APlagueCleanupItem(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer.SetDefaultSubobjectClass<UBoxComponent>(TEXT("Root"))) {

}

void APlagueCleanupItem::Server_Gunsling_Implementation() {
}

void APlagueCleanupItem::Server_EnablePhysics_Implementation(const FVector_NetQuantize& Direction) {
}

void APlagueCleanupItem::OnPickupUsed(APlayerCharacter* User, EInputKeys Key) {
}



void APlagueCleanupItem::All_Gunsling_Implementation() {
}

void APlagueCleanupItem::All_EnablePhysics_Implementation(const FVector_NetQuantize& Direction) {
}


