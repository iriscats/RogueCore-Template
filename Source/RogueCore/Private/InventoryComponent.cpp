#include "InventoryComponent.h"
#include "Net/UnrealNetwork.h"
#include "Templates/SubclassOf.h"

UInventoryComponent::UInventoryComponent(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->InventoryList = NULL;
    this->ThrownGrenadeClass = NULL;
    this->GrenadeSlotIndex = 4;
    this->AmmoBagClass = NULL;
    this->flareClass = NULL;
    this->OutOfFlaresSound = NULL;
    this->OutOfFlaresShout = NULL;
    this->FlareAngle = 0.00f;
    this->FlareCooldown = 0.00f;
    this->FlareProductionTime = 0.00f;
    this->FlareProductionTimeLeft = 0.00f;
    this->MaxFlares = 0;
    this->Flares = 0;
    this->FlareCooldownRemaining = 0.00f;
    this->bItemsLoaded = false;
    this->MiningItem = NULL;
    this->GrenadeItem = NULL;
    this->LaserPointerItem = NULL;
    this->TerrainScannerItem = NULL;
    this->ResupplyItem = NULL;
    this->RecallableSentryGunItem = NULL;
    this->AmmoBag = NULL;
    this->ItemSlots.AddDefaulted(5);
}

void UInventoryComponent::SwapItems(AItem* A, AItem* B) {
}

void UInventoryComponent::Server_ThrowItem_Implementation(AActor* Item, FVector Force, bool PlayMontage) {
}

void UInventoryComponent::Server_ThrowFlare_Implementation() {
}

void UInventoryComponent::Server_SwapItems_Implementation(AItem* A, AItem* B) {
}

void UInventoryComponent::Server_SetSlotItemId_Implementation(FItemSlotIndex Slot, FInventoryId ID) {
}

void UInventoryComponent::Server_RemoveItem_Implementation(AItem* A) {
}

void UInventoryComponent::Resupply(float percentage) {
}

void UInventoryComponent::RemoveItem(AItem* A) {
}

void UInventoryComponent::PickupItemInstance(AItem* Item) {
}

AItem* UInventoryComponent::PickupItem(TSubclassOf<AItem> itemClass) {
    return NULL;
}

void UInventoryComponent::OnRep_ItemSlots() {
}

void UInventoryComponent::OnRep_FlareClass() {
}

bool UInventoryComponent::IsTerrainScannerEquipped() const {
    return false;
}

bool UInventoryComponent::HasPickedUpItem() const {
    return false;
}

bool UInventoryComponent::HasDrink() const {
    return false;
}

AItem* UInventoryComponent::GetSlotItem(const FItemSlotIndex& Slot) {
    return NULL;
}

ARecallableSentryGunItem* UInventoryComponent::GetRecallableSentryGunItem() const {
    return NULL;
}

AItem* UInventoryComponent::GetOrCreateUnlistedItem(TSubclassOf<AItem> ItemType) {
    return NULL;
}

int32 UInventoryComponent::GetNumSlotsInUse() const {
    return 0;
}

int32 UInventoryComponent::GetNumSlots() const {
    return 0;
}

TArray<AActor*> UInventoryComponent::GetModifiableItems() const {
    return TArray<AActor*>();
}

TArray<AItem*> UInventoryComponent::GetItemsInSlot(int32 SlotIndex) const {
    return TArray<AItem*>();
}

AItem* UInventoryComponent::GetFirstItem() const {
    return NULL;
}

AItem* UInventoryComponent::GetEquippedItem() const {
    return NULL;
}

AItem* UInventoryComponent::GetCurrentItemInSlot(int32 SlotIndex) {
    return NULL;
}

AActor* UInventoryComponent::GetCarriedItem() const {
    return NULL;
}

AItem* UInventoryComponent::FindFirstItemOfCategory(EItemCategory Category) {
    return NULL;
}

void UInventoryComponent::EquipPrevious() {
}

void UInventoryComponent::EquipOrCycleSlot(int32 SlotIndex) {
}

void UInventoryComponent::EquipNext() {
}

void UInventoryComponent::Equip(AItem* Item) {
}

void UInventoryComponent::DropPickedupItem() {
}

void UInventoryComponent::Client_SetSlotItemId_Implementation(FItemSlotIndex Slot, FInventoryId ID) {
}

void UInventoryComponent::AnimationNotify2() {
}

void UInventoryComponent::AnimationNotify1() {
}

void UInventoryComponent::All_PlayThrowMontage_Implementation(AActor* Item) {
}

AItem* UInventoryComponent::AddItemToSlot(UItemID* ItemID, FItemSlotIndex Slot) {
    return NULL;
}

void UInventoryComponent::AddItemClass(TSubclassOf<AItem> itemClass) {
}

void UInventoryComponent::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const {
    Super::GetLifetimeReplicatedProps(OutLifetimeProps);

    DOREPLIFETIME(UInventoryComponent, flareClass);
    DOREPLIFETIME(UInventoryComponent, AmmoBag);
    DOREPLIFETIME(UInventoryComponent, ItemSlots);
}

bool UInventoryComponent::Server_ThrowFlare_Validate() {
    return true;
}

bool UInventoryComponent::Server_SwapItems_Validate(AItem* A, AItem* B) {
    return true;
}

bool UInventoryComponent::Server_SetSlotItemId_Validate(FItemSlotIndex Slot, FInventoryId ID) {
    return true;
}

bool UInventoryComponent::Server_RemoveItem_Validate(AItem* A) {
    return true;
}


