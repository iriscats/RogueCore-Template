#include "EquipItemAbility.h"
#include "Net/UnrealNetwork.h"

UEquipItemAbility::UEquipItemAbility(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->ItemToEquip = NULL;
    this->EquipOnDeactivate = false;
}

void UEquipItemAbility::OnRep_ItemInstance() {
}

void UEquipItemAbility::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const {
    Super::GetLifetimeReplicatedProps(OutLifetimeProps);
    
    DOREPLIFETIME(UEquipItemAbility, ItemInstance);
}


