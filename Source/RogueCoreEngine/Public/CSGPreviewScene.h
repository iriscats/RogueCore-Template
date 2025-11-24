#pragma once
#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "CSGOptions.h"
#include "Templates/SubclassOf.h"
#include "CSGPreviewScene.generated.h"

class ACSGBuilder;
class UTerrainMaterialCore;

UCLASS(Blueprintable)
class UCSGPreviewScene : public UDataAsset {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<ACSGBuilder> mesh;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FCSGOptions Settings;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 Seed;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UTerrainMaterialCore* TerrainMaterial;
    
    UCSGPreviewScene();

};

