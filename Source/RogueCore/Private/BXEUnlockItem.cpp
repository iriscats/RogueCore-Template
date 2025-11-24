#include "BXEUnlockItem.h"

UBXEUnlockItem::UBXEUnlockItem() {
    this->ItemID = NULL;
    this->DisplayText = FText::FromString(TEXT("Unlock {item}"));
    this->IsStartingWeapon = false;
}

FText UBXEUnlockItem::GetItemName() const {
    return FText::GetEmpty();
}

bool UBXEUnlockItem::GetIsGrenadeItem() const {
    return false;
}


