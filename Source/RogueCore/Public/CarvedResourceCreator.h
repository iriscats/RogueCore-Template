#pragma once
#include "CoreMinimal.h"
#include "CarveOptionsCellSize.h"
#include "ECarveFilterType.h"
#include "IRandRange.h"
#include "ResourceCreator.h"
#include "ResourceDebris.h"
#include "Templates/SubclassOf.h"
#include "UDebrisCarveMesh.h"
#include "CarvedResourceCreator.generated.h"

class AActor;
class UCarvedResourceData;
class UDebrisPositioning;
class UTerrainMaterial;
UCLASS(Blueprintable, EditInlineNew)
class UCarvedResourceCreator : public UResourceCreator {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UCarvedResourceData* Resource;
    
    bool ScaleToResourceDistribution;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UDebrisPositioning* Positioning;
    FIRandRange NumCarvers;
    float ExpensiveNoise;
    float CarveOffsetRadius;
    TSubclassOf<AActor> SpawnAttachClass;
    float AttachSpawnOffsetDistance;
    UTerrainMaterial* TerrainMaterial;
    ECarveFilterType Filter;
    CarveOptionsCellSize CarveCellSize;
    TArray<FUDebrisCarveMesh> Meshes;
    TArray<FResourceDebris> Debris;
    UCarvedResourceCreator();
};
