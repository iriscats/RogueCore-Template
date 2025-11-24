#pragma once
#include "CoreMinimal.h"
#include "ECarveFilterType.h"
#include "DebrisBase.h"
#include "DebrisInfluence.h"
#include "EDebrisCarvedType.h"
#include "Templates/SubclassOf.h"
#include "UDebrisStaticCarveMesh.h"
#include "DebrisStaticCarved.generated.h"

class AActor;
class UTerrainMaterial;
UCLASS(Blueprintable, EditInlineNew)
class UDebrisStaticCarved : public UDebrisBase {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EDebrisCarvedType CarverType;
    
    TArray<FUDebrisStaticCarveMesh> Meshes;
    UTerrainMaterial* TerrainMaterial;
    FDebrisInfluence CaveInfluenceToAdd;
    ECarveFilterType Filter;
    float CarveOffsetRadius;
    TSubclassOf<AActor> SpawnAttachClass;
    float AttachSpawnOffsetDistance;
    UDebrisStaticCarved();
};
