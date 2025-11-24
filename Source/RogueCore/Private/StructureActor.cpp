#include "StructureActor.h"
#include "Components/SceneComponent.h"
#include "TerrainPlacementComponent.h"

AStructureActor::AStructureActor(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->bAlwaysRelevant = true;
    this->RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));
    this->Root = (USceneComponent*)RootComponent;
    this->terrainPlacement = CreateDefaultSubobject<UTerrainPlacementComponent>(TEXT("terrainPlacement"));
    this->DebrisPositioning = NULL;
    this->CostCurve = NULL;
    this->TryTimes = 5;
    this->MinDistanceToTunnel = 1000.00f;
    this->terrainPlacement->SetupAttachment(RootComponent);
}


