#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "BXEProspectingLogsRewardSpawner.generated.h"

class ABXEProspectingRewardActor;
class UBXEProspectingLogsObjective;
class UCurveFloat;
class UDebrisPositioning;
class UTerrainPlacementComponent;
UCLASS(Blueprintable, NoExport)
class ABXEProspectingLogsRewardSpawner : public AActor {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, Transient, meta=(AllowPrivateAccess=true))
    UTerrainPlacementComponent* terrainPlacement;
    
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSoftClassPtr<AActor> RewardClass;
    UDebrisPositioning* DebrisPositioning;
    UCurveFloat* CostCurve;
    int32 DebrisPartsToSpawn;
    int32 MaxSpawnLocationTries;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    ABXEProspectingRewardActor* RewardInstance;
    UBXEProspectingLogsObjective* Objective;
    ABXEProspectingLogsRewardSpawner(const FObjectInitializer& ObjectInitializer);
    UFUNCTION(BlueprintCallable)
    void SpawnRewardInstance();
};
