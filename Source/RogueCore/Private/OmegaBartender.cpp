#include "OmegaBartender.h"
#include "Components/SceneComponent.h"
#include "Net/UnrealNetwork.h"

AOmegaBartender::AOmegaBartender(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->bReplicates = true;
    const FProperty* p_RemoteRole = GetClass()->FindPropertyByName("RemoteRole");
    (*p_RemoteRole->ContainerPtrToValuePtr<TEnumAsByte<ENetRole>>(this)) = ROLE_SimulatedProxy;
    this->RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));
    this->EmptySlot.AddDefaulted(4);
    this->CurrentOrder = NULL;
    this->SpecialOrder = NULL;
    this->CurrentIdleMontageIndex = -1;
    this->CurrentPourMontageIndex = -1;
    this->DrinkAmount = -1;
    this->BartenderAnimationState = EBartenderAnim::None;
    this->OmegaSalute = NULL;
    this->SaluteLoseTime = 0.00f;
    this->SaluteCooldown = 0.00f;
    this->SalutesToMakeOmegaSalute = 1;
}

void AOmegaBartender::ValidCheckPlayersInside() {
}


void AOmegaBartender::SpawnMugInHand(int32 Index, USceneComponent* Parent) {
}

void AOmegaBartender::SetSpecialOrder(UDrinkableDataAsset* Order) {
}

void AOmegaBartender::SetMug(ADrinkableActor* Mug, int32 Index) {
}

void AOmegaBartender::SetDrink(UDrinkableDataAsset* Drink) {
}

void AOmegaBartender::Server_PlayerSaluted_Implementation() {
}

void AOmegaBartender::Server_MugTaken_Implementation(ADrinkableActor* Mug) {
}

void AOmegaBartender::RemovePlayerInside(APlayerCharacter* Player) {
}





void AOmegaBartender::PlaceOrder() {
}

void AOmegaBartender::PickNewIdle() {
}

void AOmegaBartender::OnRep_Mugs() {
}

void AOmegaBartender::OnRep_GymCurrencyData() {
}

void AOmegaBartender::OnRep_GymCurrencyAmount() {
}

void AOmegaBartender::OnRep_BartenderAnimationState() {
}

void AOmegaBartender::NotifyDetachMug(FName NotifyName, int32 Index) {
}

void AOmegaBartender::MugTaken(ADrinkableActor* Mug) {
}

UAnimMontage* AOmegaBartender::GetIdleMontage(int32 Index) {
    return NULL;
}

UAnimMontage* AOmegaBartender::GetIdleArmMontage(int32 MontageIndex, int32 ArmIndex) {
    return NULL;
}

TArray<bool> AOmegaBartender::GetEmptySlots() {
    return TArray<bool>();
}

void AOmegaBartender::Client_DetachMug_Implementation(int32 Index, const FTransform& Transform) {
}

void AOmegaBartender::ChangeBartenderAnimState(EBartenderAnim State) {
}

void AOmegaBartender::BroadcastNewGymGoal(UDrinkableDataAsset* Order) {
}

void AOmegaBartender::All_MugFilled_Implementation(int32 Index) {
}

void AOmegaBartender::All_ChangeMugSlot_Implementation(int32 Index, bool Empty) {
}

void AOmegaBartender::AddPlayerInside(APlayerCharacter* Player) {
}


void AOmegaBartender::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const {
    Super::GetLifetimeReplicatedProps(OutLifetimeProps);
    
    DOREPLIFETIME(AOmegaBartender, GymCurrencyAmount);
    DOREPLIFETIME(AOmegaBartender, GymCurrencyData);
    DOREPLIFETIME(AOmegaBartender, Mugs);
    DOREPLIFETIME(AOmegaBartender, EmptySlot);
    DOREPLIFETIME(AOmegaBartender, CurrentIdleMontageIndex);
    DOREPLIFETIME(AOmegaBartender, CurrentPourMontageIndex);
    DOREPLIFETIME(AOmegaBartender, DrinkAmount);
    DOREPLIFETIME(AOmegaBartender, BartenderAnimationState);
}


