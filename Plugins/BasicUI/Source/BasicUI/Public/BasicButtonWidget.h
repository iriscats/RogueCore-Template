#pragma once
#include "CoreMinimal.h"
#include "BasicUserWidget.h"
#include "BasicButtonWidget.generated.h"

class UBasicButtonWidget;
class UButton;
class UWidgetAnimation;

UCLASS(Abstract, Blueprintable, EditInlineNew)
class BASICUI_API UBasicButtonWidget : public UBasicUserWidget {
    GENERATED_BODY()
public:
    DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FBasicButtonDelegate, UBasicButtonWidget*, InButton);
    
private:
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FBasicButtonDelegate OnButtonClicked;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FBasicButtonDelegate OnButtonHovered;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FBasicButtonDelegate OnButtonUnhovered;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UButton* InnerButton;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    UWidgetAnimation* AnimButtonClicked;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    UWidgetAnimation* AnimButtonHovered;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    UWidgetAnimation* AnimButtonUnhovered;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UButton* NativeButton;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bButtonHovered;
    
public:
    UBasicButtonWidget();

protected:
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void ReceiveButtonUnhovered();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void ReceiveButtonHovered();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void ReceiveButtonClicked();
    
    UFUNCTION(BlueprintCallable)
    void NativeButtonUnhovered();
    
    UFUNCTION(BlueprintCallable)
    void NativeButtonHovered();
    
    UFUNCTION(BlueprintCallable)
    void NativeButtonClicked();
    
};

