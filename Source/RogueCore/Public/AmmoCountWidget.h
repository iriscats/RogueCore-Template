#pragma once
#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "AmmoCountWidget.generated.h"

class AItem;
class APlayerCharacter;
class UItemAggregator;
UCLASS(Abstract, Blueprintable, EditInlineNew)
class UAmmoCountWidget : public UUserWidget {
    GENERATED_BODY()
    
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    APlayerCharacter* Character;
    
    AItem* Item;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, Transient, meta=(AllowPrivateAccess=true))
    UItemAggregator* Aggregator;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool ShowClipAndTotalAsOne;
    int32 CountThreshold;
    UAmmoCountWidget();
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnVisibleChanged(bool visible, bool showClipCount);
    void OnTotalVisibleChanged(bool visible);
    void OnReserveCountChanged(int32 Total);
    void OnReserveCapacityChanged(int32 count);
    UFUNCTION(BlueprintCallable)
    void OnItemReserveCountChanged(int32 Value);
    void OnItemReserveCapacityChanged(int32 Value);
    void OnItemEquipped(AItem* NewItem);
    void OnItemClipCountChanged(int32 Value);
    void OnItemClipCapacityChanged(int32 Value);
    void OnClipCountChanged(int32 count);
    void OnClipCapacityChanged(int32 Total);
    void DoItemEquipped();
};
