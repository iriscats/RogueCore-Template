#pragma once
#include "CoreMinimal.h"
#include "PerkActivationWidget.h"
#include "Templates/SubclassOf.h"
#include "PerkActivationWidgetWithItemMonitor.generated.h"

class AItem;
UCLASS(Abstract, Blueprintable, EditInlineNew)
class UPerkActivationWidgetWithItemMonitor : public UPerkActivationWidget {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<AItem> ItemToMonitor;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    AItem* ActiveItem;
    UPerkActivationWidgetWithItemMonitor();
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void OnStopMonitoring();
    void OnStartMonitoring();
    UFUNCTION(BlueprintCallable)
    void OnItemUnequipped(AItem* Item);
    void OnItemEquipped(AItem* Item);
    UFUNCTION(BlueprintCallable, BlueprintPure)
    AItem* GetMonitoredItem() const;
};
