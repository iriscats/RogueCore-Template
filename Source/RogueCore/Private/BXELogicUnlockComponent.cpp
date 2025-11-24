#include "BXELogicUnlockComponent.h"
#include "Net/UnrealNetwork.h"

UBXELogicUnlockComponent::UBXELogicUnlockComponent(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->Character = NULL;
    this->DamageListenerProfile = 0;
    this->TriggerBlueprintEvents = true;
}




void UBXELogicUnlockComponent::OnRep_Stacks() {
}

float UBXELogicUnlockComponent::GetTotalUpgradeValueMultiplied() const {
    return 0.0f;
}

float UBXELogicUnlockComponent::GetTotalUpgradeValue() const {
    return 0.0f;
}

int32 UBXELogicUnlockComponent::GetModifierValue_Implementation(float InAmount) const {
    return 0;
}

float UBXELogicUnlockComponent::GetClampedUpgradeValue(float Previous) const {
    return 0.0f;
}

void UBXELogicUnlockComponent::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const {
    Super::GetLifetimeReplicatedProps(OutLifetimeProps);
    
    DOREPLIFETIME(UBXELogicUnlockComponent, Stacks);
}


