#pragma once
#include "CoreMinimal.h"
#include "ResourceData.h"
#include "VeinResourceData.generated.h"

class AProceduralSetup;
class UTerrainMaterial;
class UVeinResourceCreator;
UCLASS(Blueprintable)
class UVeinResourceData : public UResourceData {
    GENERATED_BODY()

public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UTerrainMaterial* TerrainMaterial;
    
    float UnitsPerLenth;
    bool ScaleToResourceDistribution;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UVeinResourceCreator* ResourceCreator;
    UVeinResourceData();
    UFUNCTION(BlueprintCallable, BlueprintPure)
    UTerrainMaterial* GetTerrainMaterial() const;
    float GetDesiredAmount(AProceduralSetup* pls) const;
};
