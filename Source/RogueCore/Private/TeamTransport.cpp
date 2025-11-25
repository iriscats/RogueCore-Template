#include "TeamTransport.h"
#include "Components/SceneComponent.h"
#include "Net/UnrealNetwork.h"
#include "Templates/SubclassOf.h"

ATeamTransport::ATeamTransport(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->bReplicates = true;
    const FProperty* p_RemoteRole = GetClass()->FindPropertyByName("RemoteRole");
    (*p_RemoteRole->ContainerPtrToValuePtr<TEnumAsByte<ENetRole>>(this)) = ROLE_SimulatedProxy;
    this->RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("RootComponent"));
    this->DropHeight = 3500.00f;
    this->DropCurve = NULL;
    this->ArriveCurve = NULL;
    this->DepartCurve = NULL;
    this->DwarfCheckerBox = NULL;
    this->DepartureTime = -1.00f;
    this->MissionType = EMiningPodMission::DropAndReturn;
    this->WaitForPlayerSpawns = true;
    this->RequireAllPlayersInTransport = false;
    this->HasLanded = false;
    this->PodOutline = NULL;
    this->TransportState = EMiningPodState::WaitingForGameStart;
    this->rampState = EMiningPodRampState::Closed;
    this->isEscapeTransport = false;
    this->TargetDropTime = 0.00f;
    this->TargetDepartureTime = 0.00f;
    this->TimeToDrop = 0.00f;
    this->ObjectivesManager = NULL;
}

ATeamTransport* ATeamTransport::SpawnPodAtLocation(UObject* WorldContextObject, TSubclassOf<ATeamTransport> podClass, const FTransform& Transform, bool inIsEscapeTransport) {
    return NULL;
}

void ATeamTransport::SetTransportLocation(const FVector& InLocation) {
}

void ATeamTransport::SetRampState(EMiningPodRampState NewRampState) {
}




void ATeamTransport::PrepForTakeOff() {
}

void ATeamTransport::PowerUp() {
}

void ATeamTransport::PoweredUp() {
}

void ATeamTransport::OnRep_State() {
}

void ATeamTransport::OnRep_RampState() {
}

void ATeamTransport::OnPrepForTakeOff() {
}

void ATeamTransport::OnPoweringUp() {
}

void ATeamTransport::OnPoweredUp() {
}

void ATeamTransport::OnHostInsidePod(bool isInside) {
}

void ATeamTransport::OnDropStarted() {
}

void ATeamTransport::OnDroppodImpact() {
}

void ATeamTransport::OnDrillingStarted() {
}

void ATeamTransport::OnDeparting() {
}

void ATeamTransport::OnAllDwavesInsidePod(bool AllInside) {
}









void ATeamTransport::OnCountdownFinished() {
}

void ATeamTransport::OnCountdownChanged(int32 NewTime) {
}


FVector ATeamTransport::GetTransportLocation() const {
    return FVector{};
}

int32 ATeamTransport::GetTimeToDeparture() const {
    return 0;
}

bool ATeamTransport::GetHasLanded() const {
    return false;
}


void ATeamTransport::ExitSpacerig() {
}

void ATeamTransport::DropToTarget(UObject* WorldContextObject, TSubclassOf<ATeamTransport> podClass, const FTransform& dropLocation, int32 DropDelay) {
}

ATeamTransport* ATeamTransport::DropToMission(UObject* WorldContextObject, TSubclassOf<ATeamTransport> podClass, const FVector& Location) {
    return NULL;
}

void ATeamTransport::DepositAllPlayersMaterials() {
}

void ATeamTransport::Depart() {
}

void ATeamTransport::CorrectLocationsForSpawnedOnLocation() {
}

FVector ATeamTransport::AdjustLandingLocationToGround(UObject* WorldContextObjet, const FVector& initialLocation, float maxDownAdjustment, bool canAdjustUpwards) {
    return FVector{};
}

void ATeamTransport::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const {
    Super::GetLifetimeReplicatedProps(OutLifetimeProps);
    
    DOREPLIFETIME(ATeamTransport, TargetLocation);
    DOREPLIFETIME(ATeamTransport, StartLocation);
    DOREPLIFETIME(ATeamTransport, TransportState);
    DOREPLIFETIME(ATeamTransport, rampState);
    DOREPLIFETIME(ATeamTransport, isEscapeTransport);
}


