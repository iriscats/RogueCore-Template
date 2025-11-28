#pragma once
#include "CoreMinimal.h"

#include "HeroInfo.generated.h"

class UTexture2D;
USTRUCT(BlueprintType)
struct ROGUECORE_API FHeroInfo {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FText HeroName;
    
    UTexture2D* HeroIcon;
    UTexture2D* CharacterSelectorIcon;
    UTexture2D* SmallHeroIcon;
    UTexture2D* SmallSimpleHeroIcon;
    UTexture2D* SmallSimpleHeroIconDropShadow;
    UTexture2D* HeroFullSizeImage;
    FLinearColor HeroColor;
    FText HeroShortDescription;
    FText HeroLongDescription;
    FText SwitchToMessage;
    FHeroInfo();
};
