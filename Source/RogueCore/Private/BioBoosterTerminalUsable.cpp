#include "BioBoosterTerminalUsable.h"
#include "Net/UnrealNetwork.h"

UBioBoosterTerminalUsable::UBioBoosterTerminalUsable(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->IsClientPredictive = true;
    this->UseDuration = 0.50f;
    this->bInterfaceActivated = false;
}

void UBioBoosterTerminalUsable::OnRep_InterfaceActivated() {
}

void UBioBoosterTerminalUsable::OnRep_CollectedRewards(const TArray<TWeakObjectPtr<APlayerCharacter>>& OldCollectedRewards) {
}


void UBioBoosterTerminalUsable::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const {
    Super::GetLifetimeReplicatedProps(OutLifetimeProps);
    
    DOREPLIFETIME(UBioBoosterTerminalUsable, bInterfaceActivated);
    DOREPLIFETIME(UBioBoosterTerminalUsable, CollectedRewards);
}


