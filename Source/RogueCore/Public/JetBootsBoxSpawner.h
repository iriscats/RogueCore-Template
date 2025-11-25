#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "GameFramework/Actor.h"
#include "JetBootsBoxSpawner.generated.h"

class AJetBootsBox;
class UDebrisPositioning;
class UTerrainPlacementComponent;
UCLASS(Blueprintable, NoExport)
class AJetBootsBoxSpawner : public AActor {
    GENERATED_BODY()
    // UPROPERTY fields moved from protected section


public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSoftClassPtr<AActor> JetBootsBoxClass;
    
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    FFloatInterval SpawnIntervalFromDropPod;
    int32 MaxSpawnLocationTries;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    UDebrisPositioning* DebrisPositioning;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, Transient, meta=(AllowPrivateAccess=true))
    UTerrainPlacementComponent* terrainPlacement;
    AJetBootsBox* JetBootsBoxInstance;
    UClass* JetBootsBoxClassLoaded;
    AJetBootsBoxSpawner(const FObjectInitializer& ObjectInitializer);
};
