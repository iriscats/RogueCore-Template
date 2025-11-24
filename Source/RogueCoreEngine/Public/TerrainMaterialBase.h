#pragma once
#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "TerrainMaterialBase.generated.h"

UCLASS(Blueprintable)
class ROGUECOREENGINE_API UTerrainMaterialBase : public UPrimaryDataAsset {
    GENERATED_BODY()
public:
    UTerrainMaterialBase();

};

