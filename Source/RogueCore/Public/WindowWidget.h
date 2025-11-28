#pragma once
#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "WindowWidget.generated.h"

class UWindowWidget;
UCLASS(Blueprintable, EditInlineNew)
class ROGUECORE_API UWindowWidget : public UUserWidget {
    GENERATED_BODY()
    

public:
    DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FWindowDelegate, UWindowWidget*, Window);
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FWindowDelegate OnWindowClosed;
 
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bHandleCloseCommand;
    bool bResolutionDownscaleWhenOpen;
    UWindowWidget();
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void ReceiveSelectPreviousCommand();
    void ReceiveSelectNextCommand();
    void ReceiveSelectCharacterCommand();
    void ReceiveOkCommand();
    void ReceiveCloseCommand();
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    bool ReceiveCanCloseWindow(FName InActionName, FKey InKey, bool InIsMouseEvent);
    void OnShown();
    void OnNewTopWindow();
    void OnClosed();
    UFUNCTION(BlueprintCallable)
    void ConsumeCommand();
    void CloseThisWindow();
};
