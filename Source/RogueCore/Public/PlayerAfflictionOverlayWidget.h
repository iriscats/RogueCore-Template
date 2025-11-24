#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Blueprint/UserWidget.h"
#include "PlayerAfflictionOverlayWidget.generated.h"

class UPlayerAfflictionOverlay;
class UTexture2D;
UCLASS(Blueprintable, EditInlineNew)
class UPlayerAfflictionOverlayWidget : public UUserWidget {
    GENERATED_BODY()
    // UPROPERTY fields moved from protected section

public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bOverlayActive;
    
    UPlayerAfflictionOverlay* Overlay;
    UPlayerAfflictionOverlayWidget();
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void ReceiveEndOverlay();
    void ReceiveBeginOverlay(UTexture2D* InTexture, FLinearColor InTint);
    UFUNCTION(BlueprintCallable)
    void EndOverlay();
    void BeginOverlay(UPlayerAfflictionOverlay* InOverlay);
};
