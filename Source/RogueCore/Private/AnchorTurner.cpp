#include "AnchorTurner.h"
#include "Components/SceneComponent.h"
#include "Components/SkeletalMeshComponent.h"
#include "Components/SphereComponent.h"
#include "Net/UnrealNetwork.h"

AAnchorTurner::AAnchorTurner(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {

}

void AAnchorTurner::OnRep_Finished() {
}

void AAnchorTurner::OnLeftPushpoint(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex) {
}

void AAnchorTurner::OnEnteredPushpoint(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult) {
}


void AAnchorTurner::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const {
    Super::GetLifetimeReplicatedProps(OutLifetimeProps);
    
    DOREPLIFETIME(AAnchorTurner, Progress);
    DOREPLIFETIME(AAnchorTurner, Finished);
}


