#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Blueprint/UserWidget.h"
#include "CrosshairWidget.generated.h"

class AItem;
UCLASS(Blueprintable, EditInlineNew)
class UCrosshairWidget : public UUserWidget {
    GENERATED_BODY()
public:
    UCrosshairWidget();
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void SetData(AItem* Item);
    
    void OnUpgraded(AItem* Item);
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent, BlueprintPure)
    FVector2D GetExtensionOffset() const;
};
