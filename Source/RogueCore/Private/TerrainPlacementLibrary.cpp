#include "TerrainPlacementLibrary.h"

UTerrainPlacementLibrary::UTerrainPlacementLibrary() {
}

TArray<AActor*> UTerrainPlacementLibrary::PlaceTerrainActorsOnUnusedPoints(AProceduralSetup* ProceduralSetup, FWeightedTerrainPointActors WeightedActors, FUnusedTerrainPointsSettings UnusedPointsSettings) {
    return TArray<AActor*>();
}

TArray<AActor*> UTerrainPlacementLibrary::PlaceTerrainActorsInSphere(AProceduralSetup* ProceduralSetup, const FTerrainPlacementSpawnActors& Actors, const FTerrainPlacementSpawnSphere& Sphere, const FTerrainPlacementLocationRequirements LocationRequirements, const FTerrainPlacementDistanceRequirements DistanceRequirements, const FTerrainPlacementPathRequirements PathRequirements) {
    return TArray<AActor*>();
}

TArray<AActor*> UTerrainPlacementLibrary::PlaceTerrainActorsInSpawnPointsInSphere(AProceduralSetup* ProceduralSetup, const FTerrainPlacementSpawnActors& Actors, const FTerrainPlacementSpawnPoints& Points) {
    return TArray<AActor*>();
}

TArray<AActor*> UTerrainPlacementLibrary::PlaceTerrainActorsInSpawnPointsInRooms(AProceduralSetup* ProceduralSetup, const FTerrainPlacementActor Actor, const EStaticSpawnPointSelectionType PointType, const FTerrainPlacementRoomFilter Room) {
    return TArray<AActor*>();
}

TArray<AActor*> UTerrainPlacementLibrary::PlaceTerrainActorsInRooms(AProceduralSetup* ProceduralSetup, const FTerrainPlacementSpawnActors& Actors, const FTerrainPlacementSpawnRooms& Rooms, const FTerrainPlacementLocationRequirements LocationRequirements, const FTerrainPlacementDistanceRequirements DistanceRequirements, const FTerrainPlacementPathRequirements PathRequirements) {
    return TArray<AActor*>();
}

TArray<FTransform> UTerrainPlacementLibrary::ComputeTerrainPlacementsInSphere(AProceduralSetup* ProceduralSetup, const FTerrainPlacementSpawnActors& Actors, const FTerrainPlacementSpawnSphere& Sphere, const FTerrainPlacementLocationRequirements& LocationRequirements, const FTerrainPlacementDistanceRequirements& DistanceRequirements, const FTerrainPlacementPathRequirements& PathRequirements) {
    return TArray<FTransform>();
}


