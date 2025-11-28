#pragma once
#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "ButtonWidget.generated.h"

class UButton;
class UButtonWidget;
class UObject;
class UWidgetAnimation;
UCLASS(Abstract, Blueprintable, EditInlineNew)
class ROGUECORE_API UButtonWidget : public UUserWidget {
    GENERATED_BODY()
    

public:
    DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FButtonDelegate, UButtonWidget*, InButton);
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FButtonDelegate OnButtonClicked;
    FButtonDelegate OnButtonHovered;
    FButtonDelegate OnButtonUnhovered;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 DataIndex;
    UObject* DataObject;
    FString DataString;
    bool DataBool;
 
    float AnimHoveringPlaybackSpeed;
    float AnimClickedPlaybackSpeed;
    bool bButtonHovered;
    bool bButtonEnabled;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, Transient, meta=(AllowPrivateAccess=true))
    UButton* MainButton;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    UWidgetAnimation* AnimHovering;
    UWidgetAnimation* AnimClicked;
    UButtonWidget();
    UFUNCTION(BlueprintCallable)
    void SetButtonEnabled(bool InIsEnabled);
    void SetButtonData(int32 InDataIndex, UObject* InDataObject, const FString& InDataString, bool InDataBool);
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void ReceiveButtonHoveredChanged();
    void ReceiveButtonEnabledChanged();
    void ReceiveButtonClicked();
    void ButtonUnhovered();
    void ButtonHovered();
    void ButtonClicked();
};
