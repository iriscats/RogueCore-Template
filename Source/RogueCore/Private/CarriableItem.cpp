#include "CarriableItem.h"

ACarriableItem::ACarriableItem(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->StrictDeposit = false;
    this->IsDopositable = true;
}




void ACarriableItem::AttachChanged(bool Attached, const FVector& PrevScale) {
}


