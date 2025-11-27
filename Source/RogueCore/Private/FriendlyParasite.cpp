#include "FriendlyParasite.h"
#include "Components/SphereComponent.h"
#include "DeepPathfinderSceneComponent.h"
#include "DamageComponent.h"
#include "Net/UnrealNetwork.h"

AFriendlyParasite::AFriendlyParasite(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {

}

void AFriendlyParasite::SelectNewTarget(UHealthComponentBase* Health) {
}

void AFriendlyParasite::OnEnemyCollisionEnter(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult) {
}

void AFriendlyParasite::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const {
    Super::GetLifetimeReplicatedProps(OutLifetimeProps);
    
    DOREPLIFETIME(AFriendlyParasite, TargetEnemy);
}


