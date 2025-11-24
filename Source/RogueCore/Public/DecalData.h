#pragma once
#include "CoreMinimal.h"
#include "DecalData.generated.h"

class UMaterialInterface;
USTRUCT(BlueprintType)
struct FDecalData {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UMaterialInterface* DecalMaterial;
    
    float DecalSize;
    float DecalDepth;
    float LifeSpan;
    float StartDelay;
    float FadeInDuration;
    float FadeDuration;
    ROGUECORE_API FDecalData();
};
