#pragma once
#include "CoreMinimal.h"
#include "ReadyUpState.h"
#include "WindowWidget.h"
#include "ReadyUpWindow.generated.h"

UCLASS(Abstract, Blueprintable, EditInlineNew)
class UReadyUpWindow : public UWindowWidget {
    GENERATED_BODY()
    

public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FReadyUpState State;
    
    UReadyUpWindow();
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void ReceiveStateChanged();
    void ReceiveStageChanged();
};
