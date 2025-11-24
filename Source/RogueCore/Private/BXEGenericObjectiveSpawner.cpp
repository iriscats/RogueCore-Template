#include "BXEGenericObjectiveSpawner.h"
#include "Templates/SubclassOf.h"

ABXEGenericObjectiveSpawner::ABXEGenericObjectiveSpawner(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
}

bool ABXEGenericObjectiveSpawner::SpawnObjectiveActorsStatic(UObject* WorldContextObject, UBXEBlueprintControlledObjective* InObjective, const int32 InNumToSpawn, const int32 InNumToSpawnMin, int32 InNumAllowedChecks, const TSubclassOf<AActor> InSpawnedActorClass, const UDebrisPositioning* InDebrisPos, UCurveFloat* InAvoidCostCurve, TArray<AActor*>& OutSpawnedActors) {
    return false;
}

bool ABXEGenericObjectiveSpawner::SpawnObjectiveActors(UBXEBlueprintControlledObjective* InObjective, const int32& InNumToSpawn, const int32& InNumToSpawnMin, int32 InNumAllowedChecks, const TSubclassOf<AActor> InSpawnedActorClass, const UDebrisPositioning* InDebrisPos, UCurveFloat* InAvoidCostCurve, TArray<AActor*>& OutSpawnedActors) {
    return false;
}


