#pragma once
#include "CoreMinimal.h"
#include "FSDUserWidget.h"
#include "Templates/SubclassOf.h"
#include "ItemsBar.generated.h"

class AItem;
class UItemsBarIcon;
UCLASS(Abstract, Blueprintable, EditInlineNew)
class UItemsBar : public UFSDUserWidget {
    GENERATED_BODY()
    // UPROPERTY fields moved from protected section

public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<UItemsBarIcon> DefaultItemWidget;
    
    bool bShowSupplyItem;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, Transient, meta=(AllowPrivateAccess=true))
    TArray<UItemsBarIcon*> ItemIcons;
    UItemsBarIcon* SupplyIcon;
    UItemsBarIcon* SelectedIcon;
    UItemsBar();
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnSupplyItemUnequipped(UItemsBarIcon* ItemIcon);
    void OnSupplyItemEquipped(UItemsBarIcon* ItemIcon);
    void OnSupplyItemAdded(UItemsBarIcon* ItemIcon);
    void OnItemUnequipped(UItemsBarIcon* ItemIcon);
    UFUNCTION(BlueprintCallable)
    void OnItemsLoaded();
    void OnItemEquipped(UItemsBarIcon* ItemIcon);
    void OnItemClicked();
    void OnItemAdded(UItemsBarIcon* ItemIcon);
    void OnClear();
    void ItemEquipped(AItem* NewItem);
    void ItemClicked(AItem* NewItem);
};
