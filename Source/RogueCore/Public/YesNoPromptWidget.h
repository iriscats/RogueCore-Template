#pragma once
#include "CoreMinimal.h"
#include "WindowWidget.h"
#include "YesNoPromptWidget.generated.h"

class UResourceData;
UCLASS(Blueprintable, EditInlineNew)
class UYesNoPromptWidget : public UWindowWidget {
    GENERATED_BODY()
    // UPROPERTY fields moved from protected section

public:
    DECLARE_DYNAMIC_DELEGATE_OneParam(FOnYesNoClickedDelegate, bool, Yes);
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bDestroyOnClick;
    bool bCloseAllWindows;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    FOnYesNoClickedDelegate OnClickedCallback;
    UYesNoPromptWidget();
    UFUNCTION(BlueprintCallable)
    void Show(FText Title, FText Message, const UYesNoPromptWidget::FOnYesNoClickedDelegate& OnYesNoClicked);
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void SetMappedResources(const TMap<UResourceData*, int32>& Resources);
    void OnShow(const FText& Title, const FText& Message);
    void OnClicked(bool Yes);
    void Clicked(bool YesClicked);
};
