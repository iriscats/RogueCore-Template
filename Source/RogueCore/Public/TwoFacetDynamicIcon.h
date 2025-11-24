#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "DynamicIcon.h"
#include "TwoFacetDynamicIcon.generated.h"

class UMaterialInstanceDynamic;
class UTexture2D;
UCLASS(Blueprintable, EditInlineNew)
class ROGUECORE_API UTwoFacetDynamicIcon : public UDynamicIcon {
    GENERATED_BODY()
    // UPROPERTY fields moved from protected section

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))

    UMaterialInstanceDynamic* PreviewInstance;

    UTwoFacetDynamicIcon();

    UFUNCTION(BlueprintCallable)

    void UpdatePreview();



public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FLinearColor Primary1Tint1;
    
    FLinearColor Primary1Tint2;
    TSoftObjectPtr<UTexture2D> Primary1Texture;
    float Primary1Texture_BasePoint;
    float Primary1Texture_Contrast;
    FLinearColor Primary2Tint1;
    FLinearColor Primary2Tint2;
    TSoftObjectPtr<UTexture2D> Primary2Texture;
    float Primary2Texture_BasePoint;
    float Primary2Texture_Contrast;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    UMaterialInstanceDynamic* PreviewInstance;
    UTwoFacetDynamicIcon();
    UFUNCTION(BlueprintCallable)
    void UpdatePreview();
};
