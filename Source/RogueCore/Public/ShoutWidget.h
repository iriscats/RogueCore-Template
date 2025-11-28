#pragma once
#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "ShoutWidget.generated.h"

class APlayerCharacter;
UCLASS(Abstract, Blueprintable, EditInlineNew)
class UShoutWidget : public UUserWidget {
    GENERATED_BODY()
    

public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TWeakObjectPtr<APlayerCharacter> Sender;
    
    FText Text;
    float Duration;
    UShoutWidget();
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnShout();
};
