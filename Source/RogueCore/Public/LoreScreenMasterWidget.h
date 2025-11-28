#pragma once
#include "CoreMinimal.h"

#include "Blueprint/UserWidget.h"
#include "LoreScreenMasterWidget.generated.h"

class UTexture2D;
UCLASS(Blueprintable, EditInlineNew)
class ULoreScreenMasterWidget : public UUserWidget {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FText PageName;
    
    TSoftObjectPtr<UTexture2D> SolidImage;
    TSoftObjectPtr<UTexture2D> TransparentImage;
    FLinearColor BackgroundColor;
    ULoreScreenMasterWidget();
};
