#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "DistanceParam.h"
#include "EStaticSpawnPointSelectionType.h"
#include "RoomFilterParams.h"
#include "Templates/SubclassOf.h"
#include "PlaceActorParams.generated.h"

class AActor;
class AProceduralSetup;
class UCurveFloat;
class UDebrisPositioning;
USTRUCT(BlueprintType)
struct FPlaceActorParams {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 NumToSpawn;
    
    int32 NumToSpawnMin;
    int32 NumAllowedChecks;
    TSubclassOf<AActor> SpawnedActorClass;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    AProceduralSetup* setup;
    UDebrisPositioning* DebrisPositioning;
    TArray<FVector> LocationsToAvoid;
    UCurveFloat* AvoidCostCurve;
    FDistanceParam DistanceParams;
    FRoomFilterParams RoomFilterParams;
    float ChanceToUseStaticSpawnPoints;
    EStaticSpawnPointSelectionType StaticSpawnPointType;
    ROGUECORE_API FPlaceActorParams();
};
