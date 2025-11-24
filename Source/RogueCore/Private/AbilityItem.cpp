#include "AbilityItem.h"

AAbilityItem::AAbilityItem(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->AttachSocket = TEXT("Dwarf_Gauntlet_ArmL22Socket");
    this->Item_EquipAnimation = NULL;
    this->FP_EquipAnimation = NULL;
    this->TP_EquipAnimation = NULL;
    this->FP_ActivationAnimation = NULL;
    this->TP_ActivationAnimation = NULL;
    this->FP_IdleAnimation = NULL;
    this->TP_IdleAnimation = NULL;
    this->UnEquipTime = -1.00f;
    this->ActivationDelay = 0.00f;
    this->EquipCost = 1;
    this->EquipDuration = 0.25f;
    this->CharacterAnimationSet = NULL;
    this->UpperBodyCharacterAnimationSet = NULL;
    this->ActivationType = EItemActivationType::Immediate;
    this->DeactivateOnUnequip = false;
    this->UnEquipOnActivation = true;
    this->FPSuitMesh = NULL;
    this->TPSuitMesh = NULL;
}



void AAbilityItem::OnEquipFinished() {
}


void AAbilityItem::OnChargesChanged(int32 charges) {
}


void AAbilityItem::OnAbilityReleased() {
}

void AAbilityItem::OnAbilityPressed() {
}

USkeletalMeshComponent* AAbilityItem::GetTPMesh() const {
    return NULL;
}

USkeletalMeshComponent* AAbilityItem::GetFPMesh() const {
    return NULL;
}

void AAbilityItem::AnimFinished(UAnimMontage* Montage, bool interrupted) {
}


