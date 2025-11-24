#include "BXEProspectingRewardActor.h"
#include "Components/SceneComponent.h"
#include "TerrainPlacementComponent.h"
#include "TerrainScannerStaticMesh.h"

ABXEProspectingRewardActor::ABXEProspectingRewardActor(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));
    this->ScannerArea = CreateDefaultSubobject<UTerrainScannerStaticMesh>(TEXT("ScannerArea"));
    this->terrainPlacement = CreateDefaultSubobject<UTerrainPlacementComponent>(TEXT("terrainPlacement"));
    this->Root = (USceneComponent*)RootComponent;
    this->Objective = NULL;
    this->maxOffset = 10.00f;
    this->ScannerArea->SetupAttachment(RootComponent);
    this->terrainPlacement->SetupAttachment(RootComponent);
}


