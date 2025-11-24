#include "CrossbowElectroBeam.h"
#include "Net/UnrealNetwork.h"

ACrossbowElectroBeam::ACrossbowElectroBeam(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->MaxRange = 0.00f;
}

void ACrossbowElectroBeam::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const {
    Super::GetLifetimeReplicatedProps(OutLifetimeProps);
    
    DOREPLIFETIME(ACrossbowElectroBeam, MaxRange);
}


