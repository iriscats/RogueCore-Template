#include "Tether.h"
#include "Components/SkeletalMeshComponent.h"
#include "Components/SphereComponent.h"
// #include "NiagaraComponent.h"
#include "CarriableComponent.h"
#include "DamageComponent.h"
#include "InstantUsable.h"
#include "Net/UnrealNetwork.h"

ATether::ATether(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {

}

void ATether::SetIsOnGround(bool NewIsOnGround) {
}


void ATether::Explode_Implementation() {
}

UNiagaraComponent* ATether::DuplicateTetherBeam() {
    return NULL;
}

void ATether::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const {
    Super::GetLifetimeReplicatedProps(OutLifetimeProps);
    
    DOREPLIFETIME(ATether, IsOnGround);
}


