#include "BXEUnlockBase.h"

UBXEUnlockBase::UBXEUnlockBase() {
    this->UnlockUsesRandomRarity = false;
    this->ShoutNegotiationSelected = NULL;
    this->DefaultRarity = NULL;
    this->VisualSettingsOverride = NULL;
    this->UnlockType = EUnlockType::Upgrade;
    this->LogicStatus = EProductionStatus::Prototype;
    this->ParticleStatus = EProductionStatus::Unknown;
    this->SoundStatus = EProductionStatus::Unknown;
}

UUnlockVisualSettings* UBXEUnlockBase::GetVisualSettings(UBXEUnlockRarity* InRarity) const {
    return NULL;
}

EUnlockType UBXEUnlockBase::GetUnlockType() const {
    return EUnlockType::Upgrade;
}

FText UBXEUnlockBase::GetTitle() const {
    return FText::GetEmpty();
}

TArray<UWeaponTagBase*> UBXEUnlockBase::GetRelatedWeaponTags() const {
    return TArray<UWeaponTagBase*>();
}

TSoftObjectPtr<UTexture2D> UBXEUnlockBase::GetIcon() const {
    return NULL;
}

FText UBXEUnlockBase::GetDescription() const {
    return FText::GetEmpty();
}


