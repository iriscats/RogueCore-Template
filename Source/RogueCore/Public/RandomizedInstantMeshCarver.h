#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ECarveFilterType.h"
#include "EPreciousMaterialOptions.h"
#include "RandRange.h"
#include "RandomizedInstantMeshCarver.generated.h"

class USTLMeshCarver;
class UStaticMesh;
class UStaticMeshCarver;
class UTerrainMaterialBase;
UCLASS(Blueprintable, NoExport)
class ARandomizedInstantMeshCarver : public AActor {
    GENERATED_BODY()
    // UPROPERTY fields moved from protected section

public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<UStaticMesh*> CarvingMeshes;
    
    TArray<USTLMeshCarver*> STLCarvingMeshes;
    TArray<UStaticMeshCarver*> StaticMeshCarvers;
    FRandRange RandomScale;
    UTerrainMaterialBase* TerrainMaterial;
    ECarveFilterType Filter;
    EPreciousMaterialOptions PreciousMaterialAction;
    ARandomizedInstantMeshCarver(const FObjectInitializer& ObjectInitializer);
};
