#pragma once
#include "CoreMinimal.h"
#include "RecallableItem.h"
#include "Templates/SubclassOf.h"
#include "RecallableSentryGunItem.generated.h"

class AActor;
class AItem;
class ARecallableSentryGun;
class ARecallableSentryGunItem;
class UCapacityHoldingItemAggregator;
class UItemPlacerAggregator;
class UItemUpgrade;
UCLASS(Blueprintable)
class ARecallableSentryGunItem : public ARecallableItem {
    GENERATED_BODY()
    

public:
    DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FRecallableSentryGunSignature, ARecallableSentryGun*, SentryGun);
    DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FRecallableSentryGunItemSignature, ARecallableSentryGunItem*, Item);
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FRecallableSentryGunItemSignature OnActiveItemsChanged;
    FRecallableSentryGunSignature OnSelectedItemChanged;
 
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 MaxSentryCount;
    float MinDistanceBetweenSentries;
    FText RecallHoldDescription;
    float RecallHoldDuration;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UCapacityHoldingItemAggregator* AmmoCapacity;
    UItemPlacerAggregator* ItemPlacer;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TArray<UItemUpgrade*> upgrades;
    TSubclassOf<AItem> LoadoutClass;
    float SupplyStatusWeight;
    float SentryAngleRestriction;
    bool bIsUpgraded;
    ARecallableSentryGunItem(const FObjectInitializer& ObjectInitializer);
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void ReceiveItemUpgraded();
    UFUNCTION(BlueprintCallable)
    void OnDestructionRequested(AActor* Sender);
    void OnCurrentAmmoChanged(int32 Ammo);
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool HasAmmoLeft();
    ARecallableSentryGun* GetSelectedSentryGun();
    TArray<ARecallableSentryGun*> GetActiveSentryGuns();
    bool AreAllSentriesPlaced() const;
};
