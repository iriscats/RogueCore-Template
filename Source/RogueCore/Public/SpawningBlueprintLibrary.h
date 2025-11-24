#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "DeepPathFinderSize.h"
#include "EnemySpawnedDelegateDelegate.h"
#include "SpawningBlueprintLibrary.generated.h"

class UEnemyDescriptor;
class UEnemyGroupDescriptor;
class UObject;
UCLASS(Blueprintable)
class ROGUECORE_API USpawningBlueprintLibrary : public UBlueprintFunctionLibrary {
    GENERATED_BODY()
public:
    USpawningBlueprintLibrary();
    UFUNCTION(BlueprintAuthorityOnly, BlueprintCallable, meta=(WorldContext="WorldContextObject"))
    static void SpawnEnemyGroupDescriptorWithCallbackSpreadOut(UObject* WorldContextObject, UEnemyGroupDescriptor* descriptor, float Difficulty, TArray<FVector> Locations, bool Alert, DeepPathFinderSize pfSize, const FEnemySpawnedDelegate& Callback);
    
    static void SpawnEnemyGroupDescriptorSpreadOut(UObject* WorldContextObject, UEnemyGroupDescriptor* descriptor, float Difficulty, const TArray<FVector>& Locations, bool Alert, DeepPathFinderSize pfSize);
    static void SpawnEnemyGroupDescriptor(UObject* WorldContextObject, UEnemyGroupDescriptor* descriptor, float Difficulty, FVector Location, bool Alert, DeepPathFinderSize pfSize);
    static void SpawnEnemiesFromRCPool(UObject* WorldContextObject, float Difficulty, const TArray<FVector>& Locations, bool Alert, bool isConstantPreassure, bool backFillWithConstantPressure);
    static void SpawnEnemiesFromPool(UObject* WorldContextObject, float Difficulty, const TArray<FVector>& Locations, bool Alert, bool isConstantPreassure);
    static void SpawnEnemiesAtLocationWithCallback(UObject* WorldContextObject, UEnemyDescriptor* EnemyDescriptor, int32 count, FVector Location, const FEnemySpawnedDelegate& Callback, bool Alert, bool scaleToDifficulty, DeepPathFinderSize pfSize);
    static void SpawnEnemiesAtLocationsWithCallback(UObject* WorldContextObject, UEnemyDescriptor* EnemyDescriptor, int32 count, const TArray<FVector>& Locations, const FEnemySpawnedDelegate& Callback, bool Alert, bool scaleToDifficulty, DeepPathFinderSize pfSize);
    static void SpawnEnemiesAtLocations(UObject* WorldContextObject, UEnemyDescriptor* EnemyDescriptor, int32 count, const TArray<FVector>& Locations, bool Alert, bool scaleToDifficulty, DeepPathFinderSize pfSize);
    static void SpawnEnemiesAtLocation(UObject* WorldContextObject, UEnemyDescriptor* EnemyDescriptor, int32 count, FVector Location, bool Alert, bool scaleToDifficulty, DeepPathFinderSize pfSize);
    static void SpawnEnemiesAtEachLocation(UObject* WorldContextObject, UEnemyDescriptor* EnemyDescriptor, int32 count, TArray<FVector> Locations, bool Alert, bool scaleToDifficulty, DeepPathFinderSize pfSize);
    static void SpawnEnemiesAcrossLocations(UObject* WorldContextObject, UEnemyDescriptor* EnemyDescriptor, int32 count, TArray<FVector> Locations, bool Alert, bool scaleToDifficulty, DeepPathFinderSize pfSize);
    UFUNCTION(BlueprintAuthorityOnly, BlueprintCallable, BlueprintPure, meta=(WorldContext="WorldContextObject"))
    static TArray<FVector> GetSpawnPointsInRange(UObject* WorldContextObject, float distanceToPlayers, int32 spawnPointCount, DeepPathFinderSize pfSize);
    static TArray<FVector> GetSpawnPointsInCircle(UObject* WorldContextObject, FVector Location, float Radius, int32 count, bool scaleToDificulty, float maxSpawnAngle, DeepPathFinderSize pfSize);
    static TArray<FVector> GetSpawnPointsFromLocation(UObject* WorldContextObject, FVector Location, float Distance, int32 spawnPointCount, DeepPathFinderSize pfSize);
    static TArray<FVector> GetSpawnPointsAroundLocation(UObject* WorldContextObject, FVector Location, float Distance, int32 spawnPointCount, DeepPathFinderSize pfSize);
    static FVector GetSpawnPointInRange(UObject* WorldContextObject, float distanceToPlayers, DeepPathFinderSize pfSize);
    static FVector GetSpawnPointFromLocation(UObject* WorldContextObject, FVector Location, float Distance, DeepPathFinderSize pfSize);
};
