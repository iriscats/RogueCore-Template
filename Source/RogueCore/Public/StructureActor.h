#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "StructureActor.generated.h"

class UCurveFloat;
class UDebrisPositioning;
class USceneComponent;
class UTerrainPlacementComponent;
UCLASS(Blueprintable, NoExport)
class ROGUECORE_API AStructureActor : public AActor {
    GENERATED_BODY()
    // UPROPERTY fields moved from protected section


public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    USceneComponent* Root;
    
    UTerrainPlacementComponent* terrainPlacement;
 
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UDebrisPositioning* DebrisPositioning;
    UCurveFloat* CostCurve;
    int32 TryTimes;
    float MinDistanceToTunnel;
    AStructureActor(const FObjectInitializer& ObjectInitializer);
};
