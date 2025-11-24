#include "DataDrone.h"
#include "Net/UnrealNetwork.h"
#include "SpinDeathComponent.h"

ADataDrone::ADataDrone(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->SpinDeathComponent = CreateDefaultSubobject<USpinDeathComponent>(TEXT("SpinDeathComponent"));
    this->IsDataDroneFleeing = false;
}


void ADataDrone::SetDataDroneIsFleeing(bool InFleeing) {
}

void ADataDrone::OnRep_IsDataDroneFleeing(bool oldFleeing) {
}


void ADataDrone::BroadcastDataDroneKilled() {
}

void ADataDrone::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const {
    Super::GetLifetimeReplicatedProps(OutLifetimeProps);
    
    DOREPLIFETIME(ADataDrone, IsDataDroneFleeing);
}


