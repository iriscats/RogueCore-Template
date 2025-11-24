#include "ReadyUpManager.h"

UReadyUpManager::UReadyUpManager() {
}

void UReadyUpManager::StartReadyUp(const FSingleDelegate& OnCompleted) {
}

void UReadyUpManager::SetIsReady(const AFSDPlayerState* InPlayerState) {
}

bool UReadyUpManager::IsReadyingUp() const {
    return false;
}

EReadyUpStage UReadyUpManager::GetReadyUpStage() const {
    return EReadyUpStage::NotActive;
}

TArray<FReadyUpParticipant> UReadyUpManager::GetReadyUpParticipants() const {
    return TArray<FReadyUpParticipant>();
}


