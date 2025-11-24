#include "ShowroomController.h"

UShowroomController::UShowroomController(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->Stage = NULL;
    this->IsZoomedIn = false;
    this->ZoomInProgress = false;
    this->RotationDividerInDegrees = 10.00f;
    this->RotationAveragingWindowInSeconds = 0.20f;
    this->SpeedNotifierAudioComponent = NULL;
    this->SmoothedRotationSpeed = 0.00f;
}

void UShowroomController::ZoomShowroom(float Distance, bool instantZoom) {
}

void UShowroomController::ToggleZoom() {
}

void UShowroomController::SetSpeedAudioNotifier(UAudioComponent* AudioComponent, const FName AudioParameterName) {
}

void UShowroomController::SetLightChannels(AActor* Actor) {
}

void UShowroomController::RotateShowroom(float Pitch, float Yaw) {
}

void UShowroomController::ResetShowroomRotation() {
}

FRotator UShowroomController::GetShowroomRotation() {
    return FRotator{};
}


