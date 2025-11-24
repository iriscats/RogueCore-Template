#pragma once
#include "CoreMinimal.h"
#include "Components/PanelWidget.h"
#include "BasicPanelSettings.h"
#include "BasicSlotSettings.h"
#include "EBasicPanelType.h"
#include "Templates/SubclassOf.h"
#include "BasicPanel.generated.h"

class UBasicSlot;
class UWidget;

UCLASS(Blueprintable)
class BASICUI_API UBasicPanel : public UPanelWidget {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EBasicPanelType Type;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FBasicPanelSettings Settings;
    
public:
    UBasicPanel();

    UFUNCTION(BlueprintCallable)
    TArray<UWidget*> CreateChildren(TSubclassOf<UWidget> InWidgetClass, int32 InNumChildren, FBasicSlotSettings InSlotSettings, bool InClearPanelBefore);
    
    UFUNCTION(BlueprintCallable)
    UWidget* CreateChild(TSubclassOf<UWidget> InWidgetClass, FBasicSlotSettings InSlotSettings);
    
    UFUNCTION(BlueprintCallable)
    UBasicSlot* AddChildToPanel(UWidget* InChild, FBasicSlotSettings InSlotSettings);
    
    UFUNCTION(BlueprintCallable)
    void AddChildren(const TArray<UWidget*> InChildren, FBasicSlotSettings InSlotSettings, bool InClearPanelBefore);
    
};

