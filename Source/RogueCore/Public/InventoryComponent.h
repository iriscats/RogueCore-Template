#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "CarriableChangedDelegateDelegate.h"
#include "EItemCategory.h"
#include "FlareProductionDelegateDelegate.h"
#include "FlareThrownDelegateDelegate.h"
#include "FlaresDelegateDelegate.h"
#include "GrenadesDelegateDelegate.h"
#include "InventoryBase.h"
#include "InventoryComponentItemChangeDelegate.h"
#include "InventoryId.h"
#include "InventoryItemsLoadedDelegate.h"
#include "ItemDelegateDelegate.h"
#include "ItemSlot.h"
#include "ItemSlotIndex.h"
#include "ResupplyDelegateDelegate.h"
#include "Templates/SubclassOf.h"
#include "InventoryComponent.generated.h"

class AActor;
class AFlare;
class AItem;
class ALaserPointerItem;
class APickaxeItem;
class ARecallableSentryGunItem;
class ARessuplyPodItem;
class ATerrainScannerItem;
class AThrownGrenadeItem;
class UDialogDataAsset;
class UInventoryList;
class UItemID;
class UItemUpgrade;
class USoundCue;
UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class UInventoryComponent : public UInventoryBase {
    GENERATED_BODY()
    

public:
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, DuplicateTransient, EditAnywhere, meta=(AllowPrivateAccess=true))
    FInventoryItemsLoaded OnItemsLoaded;
    
    FItemDelegate OnItemClicked;
    FItemDelegate OnItemEquipped;
    FItemDelegate OnItemUnequipped;
    FInventoryComponentItemChange OnEquippedItemChanged;
    FItemDelegate OnItemAddedToInventory;
    FGrenadesDelegate OnGrenadeCountChanged;
    FFlaresDelegate OnFlareCountChanged;
    FFlareThrownDelegate OnFlareThrownServer;
    FFlaresDelegate OnMaxFlareCountChanged;
    FFlareProductionDelegate OnFlareProduction;
    FResupplyDelegate OnResuppliedEvent;
    FCarriableChangedDelegate OnCarriableChangedEvent;
 
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UInventoryList* InventoryList;
    TSubclassOf<AThrownGrenadeItem> ThrownGrenadeClass;
    int32 GrenadeSlotIndex;
    TSubclassOf<AItem> AmmoBagClass;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, ReplicatedUsing=OnRep_FlareClass, meta=(AllowPrivateAccess=true))
    TSubclassOf<AFlare> flareClass;
    FVector FlareOffset;
    USoundCue* OutOfFlaresSound;
    UDialogDataAsset* OutOfFlaresShout;
    float FlareAngle;
    float FlareCooldown;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    float FlareProductionTime;
    FLinearColor FlareChromaColor;
    float FlareProductionTimeLeft;
    int32 MaxFlares;
    int32 Flares;
    float FlareCooldownRemaining;
    TArray<UItemUpgrade*> FlareUpgrades;
    bool bItemsLoaded;
    APickaxeItem* MiningItem;
    AThrownGrenadeItem* GrenadeItem;
    ALaserPointerItem* LaserPointerItem;
    ATerrainScannerItem* TerrainScannerItem;
    ARessuplyPodItem* ResupplyItem;
    ARecallableSentryGunItem* RecallableSentryGunItem;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Replicated, meta=(AllowPrivateAccess=true))
    AActor* AmmoBag;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, ReplicatedUsing=OnRep_ItemSlots, meta=(AllowPrivateAccess=true))
    TArray<FItemSlot> ItemSlots;
    UInventoryComponent(const FObjectInitializer& ObjectInitializer);
    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
    UFUNCTION(BlueprintCallable)
    void SwapItems(AItem* A, AItem* B);
    UFUNCTION(BlueprintCallable, Reliable, Server)
    void Server_ThrowItem(AActor* Item, FVector Force, bool PlayMontage);
    UFUNCTION(BlueprintAuthorityOnly, BlueprintCallable)
    void Resupply(float percentage);
    void RemoveItem(AItem* A);
    void PickupItemInstance(AItem* Item);
    AItem* PickupItem(TSubclassOf<AItem> itemClass);
    UFUNCTION()
    void OnRep_ItemSlots();
    UFUNCTION()
    void OnRep_FlareClass();
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsTerrainScannerEquipped() const;
    bool HasPickedUpItem() const;
    bool HasDrink() const;
    AItem* GetSlotItem(const FItemSlotIndex& Slot);
    ARecallableSentryGunItem* GetRecallableSentryGunItem() const;
    AItem* GetOrCreateUnlistedItem(TSubclassOf<AItem> ItemType);
    int32 GetNumSlotsInUse() const;
    int32 GetNumSlots() const;
    TArray<AActor*> GetModifiableItems() const;
    TArray<AItem*> GetItemsInSlot(int32 SlotIndex) const;
    AItem* GetFirstItem() const;
    AItem* GetEquippedItem() const;
    AItem* GetCurrentItemInSlot(int32 SlotIndex);
    AActor* GetCarriedItem() const;
    AItem* FindFirstItemOfCategory(EItemCategory Category);
    void EquipPrevious();
    void EquipOrCycleSlot(int32 SlotIndex);
    void EquipNext();
    void Equip(AItem* Item);
    void DropPickedupItem();
    UFUNCTION(BlueprintCallable, Client, Reliable)
    void Client_SetSlotItemId(FItemSlotIndex Slot, FInventoryId ID);
    void AnimationNotify2();
    void AnimationNotify1();
    UFUNCTION(BlueprintCallable, NetMulticast, Reliable)
    void All_PlayThrowMontage(AActor* Item);
public:
    UFUNCTION(BlueprintCallable, Reliable, Server, WithValidation)
    void Server_ThrowFlare();
    UFUNCTION(BlueprintCallable, Reliable, Server, WithValidation)
    void Server_SwapItems(AItem* A, AItem* B);
    UFUNCTION(BlueprintCallable, Reliable, Server, WithValidation)
    void Server_SetSlotItemId(FItemSlotIndex Slot, FInventoryId ID);
    UFUNCTION(BlueprintCallable, Reliable, Server, WithValidation)
    void Server_RemoveItem(AItem* A);
    AItem* AddItemToSlot(UItemID* ItemID, FItemSlotIndex Slot);
    void AddItemClass(TSubclassOf<AItem> itemClass);
};
