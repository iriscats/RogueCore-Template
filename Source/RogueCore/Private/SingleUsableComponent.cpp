#include "SingleUsableComponent.h"
#include "Net/UnrealNetwork.h"

USingleUsableComponent::USingleUsableComponent(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->AudioBeginUse = NULL;
    this->AudioFailedUse = NULL;
    this->AudioCompletedUse = NULL;
    this->AudioProgress = NULL;
    this->AudioProgressParam = TEXT("Progress");
    this->BoscoLaserpointerShout = NULL;
    this->CoopUse = true;
    this->UseSpeedStat = NULL;
    this->CoopUseMultiplier = 1.00f;
    this->usable = false;
    this->TurnOffAfterUse = false;
    this->MultipleUse = false;
    this->bShowUsingUI = true;
    this->UseDuration = 0.00f;
    this->Progress = 0.00f;
    this->DesiredProgress = 0.00f;
    this->userCount = 0;
    this->AudioBeginUseInstance = NULL;
    this->AudioProgressInstance = NULL;
    this->bAudioProgressPlaying = false;
}

void USingleUsableComponent::Use(APlayerCharacter* User, EInputKeys Key, float DeltaTime) {
}

void USingleUsableComponent::SetProgress(float Value) {
}

void USingleUsableComponent::SetCanUse(bool CanUse) {
}

void USingleUsableComponent::OnRep_UserCount() {
}

void USingleUsableComponent::OnRep_Usable() {
}

void USingleUsableComponent::OnRep_DesiredProgress() {
}

void USingleUsableComponent::Cheat_Use(APlayerCharacter* User, EInputKeys Key) {
}

void USingleUsableComponent::All_PlayFailedAudio_Implementation() {
}

void USingleUsableComponent::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const {
    Super::GetLifetimeReplicatedProps(OutLifetimeProps);
    
    DOREPLIFETIME(USingleUsableComponent, usable);
    DOREPLIFETIME(USingleUsableComponent, DesiredProgress);
    DOREPLIFETIME(USingleUsableComponent, userCount);
}


