#pragma once
#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "DamageNumberWidget.generated.h"

class UFSDLabelWidget;
class UImage;
class UWidgetAnimation;
UCLASS(Blueprintable, EditInlineNew)
class UDamageNumberWidget : public UUserWidget {
    GENERATED_BODY()

public:
    UDamageNumberWidget();

    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    UWidgetAnimation* GetUpAnim();

    UWidgetAnimation* GetShakeAnimation();

    UImage* GetIcon();

    UWidgetAnimation* GetFadeAnimation();

    TArray<UWidgetAnimation*> GetDirectionAnims();

    UFSDLabelWidget* GetDamageLabel();

 
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, Transient, meta=(AllowPrivateAccess=true))
    UFSDLabelWidget* DamageLabel;

    UImage* HitTypeIcon;
};
