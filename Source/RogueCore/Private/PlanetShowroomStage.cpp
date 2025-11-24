#include "PlanetShowroomStage.h"
#include "Components/SceneComponent.h"

APlanetShowroomStage::APlanetShowroomStage(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->CameraZoomInPoint = CreateDefaultSubobject<USceneComponent>(TEXT("CameraZoomInPoint"));
    this->CameraZoomOutPoint = CreateDefaultSubobject<USceneComponent>(TEXT("CameraZoomOutPoint"));
    this->CameraZoomInPoint->SetupAttachment(CameraFocusPoint);
    this->CameraZoomOutPoint->SetupAttachment(CameraFocusPoint);
}


