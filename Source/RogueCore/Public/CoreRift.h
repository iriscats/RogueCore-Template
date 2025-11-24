#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "CoreRift.generated.h"

class UCurveFloat;
class UCurveVector;
class UInstancedStaticMeshComponent;
class USceneComponent;
class USplineComponent;
class UTerrainPlacementComponent;
UCLASS(Blueprintable, NoExport)
class ACoreRift : public AActor {
    GENERATED_BODY()
    // UPROPERTY fields moved from protected section

    UPROPERTY(BlueprintReadWrite, EditAnywhere, ReplicatedUsing=OnRep_Seed, meta=(AllowPrivateAccess=true))
    int32 Seed;

public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    USceneComponent* Root;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    USceneComponent* InitialRotationPoint;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    USceneComponent* InstancedSpikesRoot;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<UInstancedStaticMeshComponent*> SpikeMeshes;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    USplineComponent* SpikeLocationSpline;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UTerrainPlacementComponent* terrainPlacement;

protected:
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent, meta=(AllowPrivateAccess=true))
    void SpawnSpikes();

    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent, meta=(AllowPrivateAccess=true))
    void ScaleUp();

    UFUNCTION()
    void OnRep_Seed();
};
