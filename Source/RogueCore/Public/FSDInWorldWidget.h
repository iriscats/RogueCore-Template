#pragma once
#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "FSDInWorldWidget.generated.h"

UCLASS(Abstract, Blueprintable, EditInlineNew)
class UFSDInWorldWidget : public UUserWidget {
    GENERATED_BODY()

public:
    UFSDInWorldWidget();

    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void ReceiveHUDVisibilityChanged(bool InHudVisible);

protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bHUDVisibile;

    UFUNCTION(BlueprintCallable)
    void CallbackHUDVisibilityChanged(bool InHudVisible);
};
