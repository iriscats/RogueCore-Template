#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Components/ActorComponent.h"
#include "EStaticSpawnPointSelectionType.h"
#include "PlaceActorParams.h"
#include "PlaceActorPathRequirement.h"
#include "SpawnActorDelegateDelegate.h"
#include "Templates/SubclassOf.h"
#include "SpawnActorWithDebrisPosComponent.generated.h"

class AActor;
class AProceduralSetup;
class UCurveFloat;
class UDebrisPositioning;
UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class ROGUECORE_API USpawnActorWithDebrisPosComponent : public UActorComponent {
    GENERATED_BODY()
    

public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float MinDistanceBetweenSpwans;
    
    bool AddTerrainPlacementBlockers;
    bool AvoidImportantLocations;
    float MinDistanceToImportantLocations;
    USpawnActorWithDebrisPosComponent(const FObjectInitializer& ObjectInitializer);
    UFUNCTION(BlueprintCallable)
    bool PlaceActorsWithCallback(int32 NumToSpawn, int32 NumToSpawnMin, int32 NumAllowedChecks, TSubclassOf<AActor> SpawnedActorClass, AProceduralSetup* setup, float Radius, UDebrisPositioning* DebrisPositioning, const TArray<FVector>& LocationsToAvoid, UCurveFloat* AvoidCostCurve, FSpawnActorDelegate OnSpawned, FVector CustomLocation);
    bool PlaceActorsUsingParams(const FPlaceActorParams& InParams, TArray<AActor*>& OutSpawnedActors);
    bool PlaceActors(int32 NumToSpawn, int32 NumToSpawnMin, int32 NumAllowedChecks, TSubclassOf<AActor> SpawnedActorClass, AProceduralSetup* setup, float Radius, UDebrisPositioning* DebrisPositioning, const TArray<FVector>& LocationsToAvoid, UCurveFloat* AvoidCostCurve, TArray<AActor*>& OutSpawnedActors, FVector CustomLocation, float UseStaticSpawnPointProbability, EStaticSpawnPointSelectionType StaticSpawnPointType, FPlaceActorPathRequirement PathRequirement);
    bool GetLocations(int32 NumToSpawn, int32 NumToSpawnMin, int32 NumAllowedChecks, TSubclassOf<AActor> SpawnedActorClass, AProceduralSetup* setup, float Radius, UDebrisPositioning* DebrisPositioning, const TArray<FVector>& LocationsToAvoid, UCurveFloat* AvoidCostCurve, TArray<FTransform>& OutLocations, FVector CustomLocation, FPlaceActorPathRequirement PathRequirement);
    void AddTerrainPlacement(AActor* Actor, AProceduralSetup* setup);
};
