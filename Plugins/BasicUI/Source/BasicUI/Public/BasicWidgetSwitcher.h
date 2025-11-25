#pragma once
#include "CoreMinimal.h"
#include "Components/WidgetSwitcher.h"
#include "BasicPanelSettings.h"
#include "BasicWidgetSwitcher.generated.h"

class UBasicWidgetSwitcher;
class UWidget;

UCLASS(Blueprintable)
class BASICUI_API UBasicWidgetSwitcher : public UWidgetSwitcher {
    GENERATED_BODY()
public:
    DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FWidgetRemoved, UBasicWidgetSwitcher*, InSwitcher, UWidget*, InActiveWidget);
    DECLARE_DYNAMIC_MULTICAST_DELEGATE_ThreeParams(FWidgetAdded, UBasicWidgetSwitcher*, InSwitcher, int32, InIndex, UWidget*, InActiveWidget);
    DECLARE_DYNAMIC_MULTICAST_DELEGATE_ThreeParams(FActiveWidgetChanged, UBasicWidgetSwitcher*, InSwitcher, int32, InIndex, UWidget*, InActiveWidget);
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FActiveWidgetChanged OnActiveWidgetChanged;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FWidgetAdded OnWidgetAdded;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FWidgetRemoved OnWidgetRemoved;
    
 
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FBasicPanelSettings PanelSettings;
    
public:
    UBasicWidgetSwitcher();

    UFUNCTION(BlueprintCallable)
    UWidget* GotoNext(bool InReverse, bool InCircular);
    
};

