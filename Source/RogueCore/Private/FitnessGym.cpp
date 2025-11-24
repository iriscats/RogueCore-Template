#include "FitnessGym.h"
#include "Net/UnrealNetwork.h"

AFitnessGym::AFitnessGym(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->bReplicates = true;
    const FProperty* p_RemoteRole = GetClass()->FindPropertyByName("RemoteRole");
    (*p_RemoteRole->ContainerPtrToValuePtr<TEnumAsByte<ENetRole>>(this)) = ROLE_SimulatedProxy;
    this->Bartender = NULL;
    this->GymCreditPerSet = 0;
    this->RepPerSet = 0;
    this->RepsRemaining = 0;
    this->SetsRemaining = 0;
}

void AFitnessGym::StopCharacterFromHoveringActivities(APlayerCharacter* Character) {
}


void AFitnessGym::SetMonitors(TArray<AGymDisplay*> monitors) {
}

void AFitnessGym::SetBartender(AOmegaBartender* aBartender) {
}

void AFitnessGym::SetActivities(TArray<ABaseFitnessActivity*> NewActivities) {
}

void AFitnessGym::OnRep_SetsRemainingChanged(int32 Old) {
}

void AFitnessGym::OnRep_RepPerSet() {
}

void AFitnessGym::NewGoal(const int32 SetGoal, const int32 RepsPerSet) {
}

int32 AFitnessGym::GetSetsRemaining() const {
    return 0;
}

int32 AFitnessGym::GetRepsRemaining() const {
    return 0;
}

int32 AFitnessGym::GetRepPerSet() const {
    return 0;
}

TArray<AGymDisplay*> AFitnessGym::GetGymMonitors() {
    return TArray<AGymDisplay*>();
}

void AFitnessGym::GetAcitivityIcons(TArray<UTexture2D*>& outTextures, TArray<int32>& outIDs) const {
}

int32 AFitnessGym::GetAcitivityAmount() const {
    return 0;
}

bool AFitnessGym::CanPlayerStartActivity(APlayerCharacter* Player) {
    return false;
}

void AFitnessGym::AllowCharacterToHoverActivities(APlayerCharacter* Character) {
}

void AFitnessGym::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const {
    Super::GetLifetimeReplicatedProps(OutLifetimeProps);
    
    DOREPLIFETIME(AFitnessGym, RepPerSet);
    DOREPLIFETIME(AFitnessGym, SetsRemaining);
}


