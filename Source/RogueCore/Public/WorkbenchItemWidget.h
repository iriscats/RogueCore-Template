#pragma once
#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "ItemSlotIndex.h"
#include "WorkbenchItemWidget.generated.h"

class UItemData;
class UItemUpgrade;
class UObject;
class UWorkbenchItemWidget;
UCLASS(Abstract, Blueprintable, EditInlineNew)
class ROGUECORE_API UWorkbenchItemWidget : public UUserWidget {
    GENERATED_BODY()
    // UPROPERTY fields moved from protected section
public:
    DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FWorkbenchItemDelegate, UWorkbenchItemWidget*, InWidget);
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FWorkbenchItemDelegate OnItemUpgradeSelected;
 
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FItemSlotIndex UnlockSlot;
    int32 ChoiceCount;
    UItemData* ItemData;
    TArray<UItemUpgrade*> ItemUpgrades;
    TArray<UItemUpgrade*> OwnedIndices;
    TArray<UItemUpgrade*> AvailableIndices;
    UWorkbenchItemWidget();
    UFUNCTION(BlueprintCallable)
    bool SelectItemUpgrade(UObject* InUpgrade);
    void Refresh();
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void ReceiveRefresh();
    void InitializeForUse();
};
