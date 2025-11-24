#include "GuardianAbilityItem.h"

AGuardianAbilityItem::AGuardianAbilityItem(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->RequiredPerkToRepelEnemies = NULL;
    this->QuickUseShout = NULL;
    this->AuraShout = NULL;
    this->SalvoActorClass = NULL;
    this->AuraClass = NULL;
    this->Item_QuickUseAnim = NULL;
    this->Item_SecondaryQuickUseAnim = NULL;
    this->Item_AuraUseAnim = NULL;
    this->Item_SecondaryAuraUseAnim = NULL;
    this->FP_QuickUseAnim = NULL;
    this->TP_QuickUseAnim = NULL;
    this->FP_AuraUseAnim = NULL;
    this->TP_AuraUseAnim = NULL;
    this->AruaDurationPerCharge = 4.00f;
}

void AGuardianAbilityItem::Server_ToggleAura_Implementation(bool Active, FVector_NetQuantize Origin, FRotator Rotation) {
}

void AGuardianAbilityItem::Server_QuickUse_Implementation(FVector_NetQuantize Origin, FRotator Rotation) {
}

bool AGuardianAbilityItem::IsAuraAvailable() const {
    return false;
}

bool AGuardianAbilityItem::IsAuraActive() const {
    return false;
}

void AGuardianAbilityItem::DrainTick() {
}

bool AGuardianAbilityItem::CanActivateAura() const {
    return false;
}

void AGuardianAbilityItem::AnimationPlayed() {
}

void AGuardianAbilityItem::All_ToggleAura_Implementation(bool Active, FVector_NetQuantize Origin, FRotator Rotation) {
}

void AGuardianAbilityItem::All_QuickUse_Implementation(FVector_NetQuantize Origin, FRotator Rotation) {
}


