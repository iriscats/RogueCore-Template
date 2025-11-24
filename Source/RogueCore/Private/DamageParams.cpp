#include "DamageParams.h"

FDamageParams::FDamageParams() {
    this->Target = NULL;
    this->HitComponent = NULL;
    this->TargetHealth = NULL;
    this->TargetArmorDamage = NULL;
    this->TargetStats = NULL;
    this->DamageCauser = NULL;
    this->CauserWeaponTags = NULL;
    this->CauserUpgradeContainer = NULL;
    this->InstigatorUpgradeContainer = NULL;
    this->CauserListenerCollection = NULL;
    this->InstigatorListenerCollection = NULL;
    this->TargetListenerCollection = NULL;
    this->Instigator = NULL;
    this->InstigatorStats = NULL;
    this->MinionOwnerPawnStat = NULL;
    this->PhysicalMaterial = NULL;
    this->Impulse = NULL;
    this->PrefetchedCritRoll = 0.00f;
    this->PrefetchedCritChance = 0.00f;
    this->OverriddenCritLevel = 0;
    this->ClipCount = 0;
    this->BoneIndex = 0;
    this->CollectBonuses = false;
}

