#include "AdicPuddle.h"
#include "Components/SceneComponent.h"
#include "Components/SphereComponent.h"

AAdicPuddle::AAdicPuddle(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {

}


void AAdicPuddle::OnPuddleEndOverLap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex) {
}

void AAdicPuddle::OnPuddleBeginOverLap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult) {
}

