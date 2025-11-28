#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "TwoFacetDynamicIcon.h"
#include "TriFacetDynamicIcon.generated.h"

class UTexture2D;
UCLASS(Blueprintable, EditInlineNew)
class ROGUECORE_API UTriFacetDynamicIcon : public UTwoFacetDynamicIcon {
    GENERATED_BODY()
    

public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FLinearColor Primary3Tint1;
    
    FLinearColor Primary3Tint2;
    TSoftObjectPtr<UTexture2D> Primary3Texture;
    float Primary3Texture_BasePoint;
    float Primary3Texture_Contrast;
    UTriFacetDynamicIcon();
};
