#pragma once
#include "CoreMinimal.h"
#include "CarveOptionsCellSize.h"
#include "ECarveFilterType.h"
#include "DebrisBase.h"
#include "DebrisInfluence.h"
#include "EDebrisCarvedType.h"
#include "Templates/SubclassOf.h"
#include "UDebrisCarveMesh.h"
#include "DebrisCarved.generated.h"

class AActor;
class UTerrainMaterial;
UCLASS(Blueprintable, EditInlineNew)
class UDebrisCarved : public UDebrisBase {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EDebrisCarvedType CarverType;
    
    TArray<FUDebrisCarveMesh> Meshes;
    UTerrainMaterial* TerrainMaterial;
    FDebrisInfluence CaveInfluenceToAdd;
    ECarveFilterType Filter;
    float ExpensiveNoise;
    CarveOptionsCellSize CarveCellSize;
    int32 MinNumCarves;
    int32 MaxNumCarves;
    float CarveOffsetRadius;
    TSubclassOf<AActor> SpawnAttachClass;
    float AttachSpawnOffsetDistance;
    UDebrisCarved();
};
