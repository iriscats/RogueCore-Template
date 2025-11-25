#include "ThrownGrenadeItem.h"
#include "GrenadeCountAggregator.h"
#include "Net/UnrealNetwork.h"

AThrownGrenadeItem::AThrownGrenadeItem(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->GrenadeMeshInstance = NULL;
    this->CookSound = NULL;
    this->Aggregator = CreateDefaultSubobject<UGrenadeCountAggregator>(TEXT("GrenadeAggregator"));
    this->FPAnimInstance = NULL;
    this->TPAnimInstance = NULL;
    this->CharacterAnimationSet = NULL;
    this->DefaultGrenadeAnimationSet = NULL;
    this->GrenadeClass = NULL;
    this->ThrowAngle = 0.00f;
    this->GrenadeCooldownRemaining = 0.00f;
    this->MaxGrenades = 0;
    this->Grenades = 0;
    this->State = EThrownGrenadeItemState::NotEquipped;
    this->CooldownIsDone = true;
    this->HasRejoinedInitialized = false;
}


void AThrownGrenadeItem::SetRemainingCooldown(float CoolDown) {
}

void AThrownGrenadeItem::Server_ThrowGrenade_Implementation(const FVector& StartLocation, const float& cookTime) {
}

void AThrownGrenadeItem::Server_SetState_Implementation(EThrownGrenadeItemState itemState) {
}

void AThrownGrenadeItem::Server_Resupply(float percentage) {
}

void AThrownGrenadeItem::Server_HasReturnedToSender() {
}

void AThrownGrenadeItem::ResupplyGrenadesAmount(const int32& amount) {
}

void AThrownGrenadeItem::ResupplyGrenades(float percentage) {
}

TArray<FVector> AThrownGrenadeItem::PredictGrenadePath() {
    return TArray<FVector>();
}


void AThrownGrenadeItem::OnRep_State() {
}

void AThrownGrenadeItem::OnRep_GrenadeCount() {
}

void AThrownGrenadeItem::OnRep_GrenadeClass() {
}


void AThrownGrenadeItem::GrenadeThrowFinished() {
}

void AThrownGrenadeItem::GetPredictedLastPosAndVelocity(FVector& Pos, FVector& Velocity) {
}

float AThrownGrenadeItem::GetGrenadeThrowVelocity() const {
    return 0.0f;
}

FRotator AThrownGrenadeItem::GetGrenadeThrowRotation() const {
    return FRotator{};
}

float AThrownGrenadeItem::GetGrenadeGravity() const {
    return 0.0f;
}

float AThrownGrenadeItem::GetGrenadeDuration() const {
    return 0.0f;
}

void AThrownGrenadeItem::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const {
    Super::GetLifetimeReplicatedProps(OutLifetimeProps);
    
    DOREPLIFETIME(AThrownGrenadeItem, GrenadeClass);
    DOREPLIFETIME(AThrownGrenadeItem, Grenades);
    DOREPLIFETIME(AThrownGrenadeItem, State);
    DOREPLIFETIME(AThrownGrenadeItem, CooldownIsDone);
    DOREPLIFETIME(AThrownGrenadeItem, HasRejoinedInitialized);
}


