#include "AuraBubble.h"
#include "Components/SceneComponent.h"
#include "Components/SphereComponent.h"
#include "Net/UnrealNetwork.h"

AAuraBubble::AAuraBubble(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {

}



void AAuraBubble::OnRep_IsActive() {
}

void AAuraBubble::OnActorLeftAura(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex) {
}

void AAuraBubble::OnActorEnteredAura(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult) {
}

void AAuraBubble::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const {
    Super::GetLifetimeReplicatedProps(OutLifetimeProps);
    
    DOREPLIFETIME(AAuraBubble, IsActive);
}


