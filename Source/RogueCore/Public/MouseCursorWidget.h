#pragma once
#include "CoreMinimal.h"
#include "EFSDInputSource.h"
#include "FSDUserWidget.h"
#include "MouseCursorWidget.generated.h"

UCLASS(Abstract, Blueprintable, EditInlineNew)
class UMouseCursorWidget : public UFSDUserWidget {
    GENERATED_BODY()
    // UPROPERTY fields moved from protected section

public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EFSDInputSource TargetInput;
    
    bool bIsHovering;
    UMouseCursorWidget();
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnUnhover();
    UFUNCTION(BlueprintCallable)
    void OnInputSourceChanged(EFSDInputSource Source);
    void OnHover();
};
