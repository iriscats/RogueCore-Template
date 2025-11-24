#include "FitnessGymStateComponent.h"
#include "Net/UnrealNetwork.h"

UFitnessGymStateComponent::UFitnessGymStateComponent(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->StateId = 19;
    this->FitnessInputComponent = NULL;
    this->GymActivity = NULL;
    this->CurrentExerciseIcon = NULL;
    this->CurrentAnimState = EGymAnimationState::None;
    this->StressLevel = 0.00f;
    this->RepsPerSet = -1;
}

void UFitnessGymStateComponent::TamperWithEquipment_Implementation() {
}

void UFitnessGymStateComponent::StartActivity_Implementation(ABaseFitnessActivity* Activity) {
}

void UFitnessGymStateComponent::SetIFrame(const bool On) {
}

void UFitnessGymStateComponent::SetHitSize(float Size) {
}


void UFitnessGymStateComponent::SetComplete_Implementation() {
}

void UFitnessGymStateComponent::VisiblityChanged_Implementation(bool visible) {
}

void UFitnessGymStateComponent::SetCharacterStartPosition_Implementation() {
}

void UFitnessGymStateComponent::SendStressLevels_Implementation(float Stress) {
}

void UFitnessGymStateComponent::ForceEndActivity_Implementation() {
}

void UFitnessGymStateComponent::EndActivity_Implementation() {
}

void UFitnessGymStateComponent::ChangeAnimState_Implementation(EGymAnimationState NewState) {
}

void UFitnessGymStateComponent::SendScore_Implementation(int32 score) {
}

void UFitnessGymStateComponent::SendPersonalBest_Implementation(int32 score) {
}

void UFitnessGymStateComponent::RepComplete_Implementation() {
}

void UFitnessGymStateComponent::OnRep_StressLevel() {
}

void UFitnessGymStateComponent::OnRep_RepsPerSet() {
}

void UFitnessGymStateComponent::OnRep_GymActivity() {
}

void UFitnessGymStateComponent::OnRep_AnimState(EGymAnimationState oldState) {
}

void UFitnessGymStateComponent::OnNewGoalRecieved(int32 Sets, int32 RepsPerSets) {
}

void UFitnessGymStateComponent::IncreaseSpeedWithInterval() {
}

void UFitnessGymStateComponent::IncreaseSpeed(float amount) {
}

void UFitnessGymStateComponent::IncreaseDifficultyWithInterval() {
}

void UFitnessGymStateComponent::IncreaseDifficulty(int32 amount) {
}

int32 UFitnessGymStateComponent::GetRepsLeft_Implementation() const {
    return 0;
}

int32 UFitnessGymStateComponent::GetPersonalBest() {
    return 0;
}

UAnimSequence* UFitnessGymStateComponent::GetAnimSequence(EGymAnimationState State) {
    return NULL;
}

void UFitnessGymStateComponent::ForceEndActivity(APlayerCharacter* Player) {
}

void UFitnessGymStateComponent::AnimNotifyCheck(FName NotifyName) {
}

void UFitnessGymStateComponent::AddMiniGameHUD(int32 Index, UGymMinigameBaseWidget* HUD) {
}

void UFitnessGymStateComponent::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const {
    Super::GetLifetimeReplicatedProps(OutLifetimeProps);
    
    DOREPLIFETIME(UFitnessGymStateComponent, GymActivity);
    DOREPLIFETIME(UFitnessGymStateComponent, CurrentAnimState);
    DOREPLIFETIME(UFitnessGymStateComponent, StressLevel);
    DOREPLIFETIME(UFitnessGymStateComponent, RepsPerSet);
}


