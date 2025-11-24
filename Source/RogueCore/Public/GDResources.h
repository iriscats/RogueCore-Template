#pragma once
#include "CoreMinimal.h"
#include "GDResources.generated.h"

class UGemResourceData;
class UResourceData;
USTRUCT(BlueprintType)
struct FGDResources {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UResourceData* CreditsResource;
    
    UResourceData* Fashionite;
    UResourceData* MOMResource;
    UResourceData* GoldResource;
    UResourceData* NitraResource;
    UResourceData* HollomiteResource;
    UResourceData* MagniteResource;
    UResourceData* NeromiteResource;
    UResourceData* QuantriteResource;
    UResourceData* UmaniteResource;
    UResourceData* CropaniteResource;
    UResourceData* DystrumResource;
    UResourceData* IronResource;
    UResourceData* EnorResource;
    UResourceData* BismorResource;
    UResourceData* OilShaleResource;
    UResourceData* Barly1;
    UResourceData* Barly2;
    UResourceData* Barly3;
    UResourceData* Barly4;
    UResourceData* Squat;
    UResourceData* Deadlift;
    UResourceData* LateralRaises;
    UResourceData* Curls;
    UResourceData* XPResource;
    UGemResourceData* JadizResource;
    UGemResourceData* BittergemResource;
    UGemResourceData* MotherlodeGemResource;
    UResourceData* RedSugarResource;
    UResourceData* BlankSchematics;
    UResourceData* ExpeniteResource;
    UResourceData* CameraResource;
    TArray<UResourceData*> CraftingResources;
    TArray<UResourceData*> AllResources;
    float FashioniteToCredits;
    float FashioniteToMinerals;
    ROGUECORE_API FGDResources();
};
