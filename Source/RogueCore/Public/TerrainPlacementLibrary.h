#pragma once
#include "CoreMinimal.h"

#include "Kismet/BlueprintFunctionLibrary.h"
#include "EStaticSpawnPointSelectionType.h"
#include "TerrainPlacementActor.h"
#include "TerrainPlacementDistanceRequirements.h"
#include "TerrainPlacementLocationRequirements.h"
#include "TerrainPlacementPathRequirements.h"
#include "TerrainPlacementRoomFilter.h"
#include "TerrainPlacementSpawnActors.h"
#include "TerrainPlacementSpawnPoints.h"
#include "TerrainPlacementSpawnRooms.h"
#include "TerrainPlacementSpawnSphere.h"
#include "UnusedTerrainPointsSettings.h"
#include "WeightedTerrainPointActors.h"
#include "TerrainPlacementLibrary.generated.h"

class AActor;
class AProceduralSetup;
UCLASS(Blueprintable)
class ROGUECORE_API UTerrainPlacementLibrary : public UBlueprintFunctionLibrary {
    GENERATED_BODY()
public:
    UTerrainPlacementLibrary();
    UFUNCTION(BlueprintCallable)
    static TArray<AActor*> PlaceTerrainActorsOnUnusedPoints(AProceduralSetup* ProceduralSetup, FWeightedTerrainPointActors WeightedActors, FUnusedTerrainPointsSettings UnusedPointsSettings);
    
    static TArray<AActor*> PlaceTerrainActorsInSphere(AProceduralSetup* ProceduralSetup, const FTerrainPlacementSpawnActors& Actors, const FTerrainPlacementSpawnSphere& Sphere, const FTerrainPlacementLocationRequirements LocationRequirements, const FTerrainPlacementDistanceRequirements DistanceRequirements, const FTerrainPlacementPathRequirements PathRequirements);
    static TArray<AActor*> PlaceTerrainActorsInSpawnPointsInSphere(AProceduralSetup* ProceduralSetup, const FTerrainPlacementSpawnActors& Actors, const FTerrainPlacementSpawnPoints& Points);
    static TArray<AActor*> PlaceTerrainActorsInSpawnPointsInRooms(AProceduralSetup* ProceduralSetup, const FTerrainPlacementActor Actor, const EStaticSpawnPointSelectionType PointType, const FTerrainPlacementRoomFilter Room);
    static TArray<AActor*> PlaceTerrainActorsInRooms(AProceduralSetup* ProceduralSetup, const FTerrainPlacementSpawnActors& Actors, const FTerrainPlacementSpawnRooms& Rooms, const FTerrainPlacementLocationRequirements LocationRequirements, const FTerrainPlacementDistanceRequirements DistanceRequirements, const FTerrainPlacementPathRequirements PathRequirements);
    static TArray<FTransform> ComputeTerrainPlacementsInSphere(AProceduralSetup* ProceduralSetup, const FTerrainPlacementSpawnActors& Actors, const FTerrainPlacementSpawnSphere& Sphere, const FTerrainPlacementLocationRequirements& LocationRequirements, const FTerrainPlacementDistanceRequirements& DistanceRequirements, const FTerrainPlacementPathRequirements& PathRequirements);
};
