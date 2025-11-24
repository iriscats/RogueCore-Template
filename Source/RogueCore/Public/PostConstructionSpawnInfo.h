#pragma once
#include "CoreMinimal.h"
#include "EStaticSpawnPointSelectionType.h"
#include "PostConstructionSpawnInfo.generated.h"

class AActor;
class UCurveFloat;
class UDebrisPositioning;
class UGenericMutator;
USTRUCT(BlueprintType)
struct FPostConstructionSpawnInfo {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSoftClassPtr<AActor> SoftActorClass;
    
    int32 SpawnAmount;
    UDebrisPositioning* Positioning;
    UCurveFloat* DistanceCostCurve;
    UGenericMutator* SpawnChanceMutator;
    float MinDistanceToOtherLocations;
    float MinDistanceToImportantLocations;
    bool OnlySpawnOnFirstStage;
    float UseStaticSpawnPointProbability;
    EStaticSpawnPointSelectionType StaticSpawnPointType;
    bool CanBackfillStaticSpawnPoint;
    TSoftClassPtr<AActor> CustomActorSoftClass;
    float MaxDistanceToCustomActor;
    ROGUECORE_API FPostConstructionSpawnInfo();
};
