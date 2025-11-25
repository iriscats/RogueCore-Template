#pragma once
#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "CustomAmmoCountWidget.generated.h"

class AItem;
UCLASS(Abstract, Blueprintable, EditInlineNew)
class UCustomAmmoCountWidget : public UUserWidget {
    GENERATED_BODY()

public:
    UCustomAmmoCountWidget();

    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void ReceiveItemSet();

 
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TWeakObjectPtr<AItem> Item;
};
