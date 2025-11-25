#pragma once
#include "CoreMinimal.h"
#include "Components/WidgetSwitcherSlot.h"
#include "BasicWidgetSwitcherSlot.generated.h"

class UBasicWidgetSwitcherSlot;
class UTexture2D;

UCLASS(Blueprintable)
class UBasicWidgetSwitcherSlot : public UWidgetSwitcherSlot {
    GENERATED_BODY()
public:
    DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FSlotDelegate, UBasicWidgetSwitcherSlot*, InSlot);
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSlotDelegate OnInfoChanged;
    
 
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FText Title;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UTexture2D* Icon;
    
public:
    UBasicWidgetSwitcherSlot();

    UFUNCTION(BlueprintCallable)
    void SetTitleAndIcon(FText InTitle, UTexture2D* InIcon);
    
    UFUNCTION(BlueprintCallable)
    void SetTitle(FText InTitle);
    
    UFUNCTION(BlueprintCallable)
    void SetIcon(UTexture2D* InIcon);
    
};

