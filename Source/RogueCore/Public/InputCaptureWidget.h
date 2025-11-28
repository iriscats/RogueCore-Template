#pragma once
#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "CustomKeySetting.h"
#include "EKeyBindingSlot.h"
#include "InputCaptureWidget.generated.h"

UCLASS(Blueprintable, EditInlineNew)
class ROGUECORE_API UInputCaptureWidget : public UUserWidget {
    GENERATED_BODY()
    

public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FCustomKeySetting Settings;
    
    EKeyBindingSlot InputSlot;
    bool bIsGamepadKey;
    bool bCapturing;
    UInputCaptureWidget();
    UFUNCTION(BlueprintCallable)
    void SetData(const FCustomKeySetting InSettings, EKeyBindingSlot InInputSlot, bool InIsGamepadKey);
    void SetCurrentBinding(const FKey& InKey);
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void ReceiveKeyChanged(FKey InKey);
    void ReceiveKeyCaptured(FKey InKey);
    void ReceiveCapturingChanged(bool InCapturing);
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FKey GetCurrentBinding() const;
    bool FindCurrentSettingsForKey(const FKey& InKey, FCustomKeySetting& OutSettings);
    void ClearCurrentBinding();
    void BindActionToKey(const FCustomKeySetting& InAction, const FKey& InKey, EKeyBindingSlot InSlot, bool SaveToDisk);
};
