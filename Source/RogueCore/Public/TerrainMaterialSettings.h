#pragma once
#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "DecalData.h"
#include "TerrainMaterialSettings.generated.h"

class UTerrainMaterial;
UCLASS(Blueprintable, Const)
class UTerrainMaterialSettings : public UDataAsset {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, EditFixedSize, meta=(AllowPrivateAccess=true))
    TArray<FDecalData> TwoHits;
    
    TArray<FDecalData> ThreeHits;
    TArray<FDecalData> FourHits;
    TArray<FDecalData> FiveHits;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<UTerrainMaterial*> PlagueMaterials;
    float InfectionIncreasePerPlagueHit;
    UTerrainMaterialSettings();
};
