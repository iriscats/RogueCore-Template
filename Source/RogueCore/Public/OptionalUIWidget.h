#pragma once
#include "CoreMinimal.h"
#include "UObject/UnrealType.h"
#include "Blueprint/UserWidget.h"
#include "OptionalUIWidget.generated.h"

class UOptionalUICategory;
UCLASS(Abstract, Blueprintable, EditInlineNew)
class UOptionalUIWidget : public UUserWidget {
    GENERATED_BODY()
    // UPROPERTY fields moved from protected section

public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UOptionalUICategory* Category;
    
    ESlateVisibility VisibleFlag;
    ESlateVisibility HiddenFlag;
    UOptionalUIWidget();
    UFUNCTION(BlueprintCallable)
    void OnVisibilityChanged(UOptionalUICategory* UICategory, bool IsVisible);
};
