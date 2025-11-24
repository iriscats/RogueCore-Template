#pragma once
#include "CoreMinimal.h"
#include "VanityItem.h"
#include "BeardColorVanityItem.generated.h"

class UMaterialInterface;
UCLASS(Blueprintable, EditInlineNew)
class UBeardColorVanityItem : public UVanityItem {
    GENERATED_BODY()
    // UPROPERTY fields moved from protected section
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSoftObjectPtr<UMaterialInterface> HairColor;
    
    TSoftObjectPtr<UMaterialInterface> EyebrowColor;
    TSoftObjectPtr<UMaterialInterface> MoustacheColor;
    TSoftObjectPtr<UMaterialInterface> SideburnColor;
    TSoftObjectPtr<UMaterialInterface> BeardColor;
    TSoftObjectPtr<UMaterialInterface> TransparentColor;
    UBeardColorVanityItem();
};
