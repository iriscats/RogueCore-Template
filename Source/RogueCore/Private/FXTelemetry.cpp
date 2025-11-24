#include "FXTelemetry.h"

UFXTelemetry::UFXTelemetry() {
}

void UFXTelemetry::OnStageStart() {
}

void UFXTelemetry::OnStageCompleted() {
}

void UFXTelemetry::OnServerKickPlayer(const FString& KickReason) {
}

void UFXTelemetry::OnRefreshRunData() {
}

void UFXTelemetry::OnRefreshLivePlayerData(APlayerCharacter* Character) {
}

void UFXTelemetry::OnNewRun(URun* Run) {
}

void UFXTelemetry::OnNewCharacter(APlayerCharacter* Character) {
}

void UFXTelemetry::OnNetworkFailure(UWorld* World, UNetDriver* NetDriver, TEnumAsByte<ENetworkFailure::Type> failType, const FString& ErrorMessage) {
}

void UFXTelemetry::OnLocalPlayerKicked(const FString& KickReason) {
}

void UFXTelemetry::HandleCreateSessionComplete(FName SessionName, bool Successfull) {
}


