#include "RecallableProjectileComponent.h"
#include "Net/UnrealNetwork.h"

URecallableProjectileComponent::URecallableProjectileComponent(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->bAutoActivate = true;
    this->UpdatedComponent = NULL;
    this->usable = NULL;
    this->RecallTarget = NULL;
    this->RecallStartTime = 1.00f;
    this->RecallSpeed = 0.30f;
    this->FPMeshComponent = NULL;
    this->IsRecallable = false;
}

void URecallableProjectileComponent::Server_SetRecallTarget_Implementation(APlayerCharacter* Player, const FTransform& startTrans) {
}

void URecallableProjectileComponent::OnUsedBy(APlayerCharacter* Player, EInputKeys Key) {
}

void URecallableProjectileComponent::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const {
    Super::GetLifetimeReplicatedProps(OutLifetimeProps);
    
    DOREPLIFETIME(URecallableProjectileComponent, RecallTarget);
    DOREPLIFETIME(URecallableProjectileComponent, StartTransform);
    DOREPLIFETIME(URecallableProjectileComponent, IsRecallable);
}


