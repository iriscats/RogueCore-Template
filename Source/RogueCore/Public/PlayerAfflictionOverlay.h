#pragma once
#include "CoreMinimal.h"

#include "Engine/DataAsset.h"
#include "Templates/SubclassOf.h"
#include "PlayerAfflictionOverlay.generated.h"

class UPlayerAfflictionOverlayWidget;
class USoundCue;
class UTexture2D;
UCLASS(Blueprintable)
class UPlayerAfflictionOverlay : public UDataAsset {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UTexture2D* Texture;
    
    FLinearColor TextureTint;
    TSubclassOf<UPlayerAfflictionOverlayWidget> WidgetOverride;
    int32 ZOrder;
    TSoftObjectPtr<USoundCue> Audio2D_OnBegin;
    UPlayerAfflictionOverlay();
};
