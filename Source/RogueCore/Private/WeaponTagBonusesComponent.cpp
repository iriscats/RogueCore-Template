#include "WeaponTagBonusesComponent.h"
#include "Net/UnrealNetwork.h"

UWeaponTagBonusesComponent::UWeaponTagBonusesComponent(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
}

void UWeaponTagBonusesComponent::OnRep_Bonuses() {
}

float UWeaponTagBonusesComponent::GetBonuses(ETagBonus Bonus, const TArray<UWeaponTagBase*>& Tags) const {
    return 0.0f;
}

void UWeaponTagBonusesComponent::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const {
    Super::GetLifetimeReplicatedProps(OutLifetimeProps);
    
    DOREPLIFETIME(UWeaponTagBonusesComponent, Bonuses);
}


