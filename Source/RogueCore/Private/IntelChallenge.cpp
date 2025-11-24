#include "IntelChallenge.h"

UIntelChallenge::UIntelChallenge() {
    this->IntelReward = 0;
    this->bIsActive = false;
}

void UIntelChallenge::SetStatValue(const float NewValue) {
}

void UIntelChallenge::OnStopTracking_Implementation() {
}

void UIntelChallenge::OnStartTracking_Implementation() {
}

void UIntelChallenge::MarkChallengeComplete() {
}

int32 UIntelChallenge::GetTargetValue_Implementation() const {
    return 0;
}

int32 UIntelChallenge::GetStatValueAsInt() const {
    return 0;
}

float UIntelChallenge::GetStatValue() const {
    return 0.0f;
}

int32 UIntelChallenge::GetIntelReward() const {
    return 0;
}

void UIntelChallenge::BroadcastComplete() {
}


