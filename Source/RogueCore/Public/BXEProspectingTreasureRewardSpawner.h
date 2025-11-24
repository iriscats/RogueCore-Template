#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Templates/SubclassOf.h"
#include "BXEProspectingTreasureRewardSpawner.generated.h"

class ABXEScannableRewardActor;
class UBXEObjectiveLostDronesTreasure;
class UCurveFloat;
class UDebrisPositioning;
class UTerrainPlacementComponent;
UCLASS(Blueprintable, NoExport)
class ABXEProspectingTreasureRewardSpawner : public AActor {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, Transient, meta=(AllowPrivateAccess=true))
    UTerrainPlacementComponent* terrainPlacement;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<AActor> RewardClass;
    UDebrisPositioning* DebrisPositioning;
    UCurveFloat* CostCurve;
    int32 DebrisPartsToSpawn;
    int32 MaxSpawnLocationTries;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    ABXEScannableRewardActor* RewardInstance;
    UBXEObjectiveLostDronesTreasure* Objective;
    ABXEProspectingTreasureRewardSpawner(const FObjectInitializer& ObjectInitializer);
    UFUNCTION(BlueprintCallable)
    void SpawnRewardInstance();
};
