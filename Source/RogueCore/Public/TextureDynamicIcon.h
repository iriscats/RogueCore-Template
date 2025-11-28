#pragma once
#include "CoreMinimal.h"
#include "DynamicIcon.h"
#include "TextureDynamicIcon.generated.h"

class UMaterialInstanceDynamic;
class UTexture2D;
UCLASS(Blueprintable, EditInlineNew)
class ROGUECORE_API UTextureDynamicIcon : public UDynamicIcon {
    GENERATED_BODY()
    

public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSoftObjectPtr<UTexture2D> Texture;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    UMaterialInstanceDynamic* PreviewInstance;
    UTextureDynamicIcon();
    UFUNCTION(BlueprintCallable)
    void UpdatePreview();
};
