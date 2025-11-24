#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Templates/SubclassOf.h"
#include "BXEGenericObjectiveSpawner.generated.h"

class UBXEBlueprintControlledObjective;
class UCurveFloat;
class UDebrisPositioning;
class UObject;
UCLASS(Blueprintable, NoExport)
class ABXEGenericObjectiveSpawner : public AActor {
    GENERATED_BODY()
public:
    ABXEGenericObjectiveSpawner(const FObjectInitializer& ObjectInitializer);
    UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContextObject"))
    static bool SpawnObjectiveActorsStatic(UObject* WorldContextObject, UBXEBlueprintControlledObjective* InObjective, const int32 InNumToSpawn, const int32 InNumToSpawnMin, int32 InNumAllowedChecks, const TSubclassOf<AActor> InSpawnedActorClass, const UDebrisPositioning* InDebrisPos, UCurveFloat* InAvoidCostCurve, TArray<AActor*>& OutSpawnedActors);
    
    UFUNCTION(BlueprintCallable)
    bool SpawnObjectiveActors(UBXEBlueprintControlledObjective* InObjective, const int32& InNumToSpawn, const int32& InNumToSpawnMin, int32 InNumAllowedChecks, const TSubclassOf<AActor> InSpawnedActorClass, const UDebrisPositioning* InDebrisPos, UCurveFloat* InAvoidCostCurve, TArray<AActor*>& OutSpawnedActors);
};
