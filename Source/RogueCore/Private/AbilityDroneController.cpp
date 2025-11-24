#include "AbilityDroneController.h"
#include "Components/SceneComponent.h"
#include "Components/SkeletalMeshComponent.h"
#include "Net/UnrealNetwork.h"

AAbilityDroneController::AAbilityDroneController(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));
    this->FPBirdMesh = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("FP_BirdMeshComp"));
    this->TPBirdMesh = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("TP_BirdMeshComp"));
    this->SentOutStatus = NULL;
    this->FP_PetDrone = NULL;
    this->TP_PetDrone = NULL;
    this->Bird_Pet = NULL;
    this->Bird_Equip = NULL;
    this->Item_AlternateEquip = NULL;
    this->Bird_ReceivedBird = NULL;
    this->Item_ReceivedBird = NULL;
    this->FP_ReceivedBird = NULL;
    this->TP_ReceivedBird = NULL;
    this->Item_Activation = NULL;
    this->RecallAnim = NULL;
    this->TP_RecallAnim = NULL;
    this->FP_ReactivateDroneAnim = NULL;
    this->TP_ReactivateDroneAnim = NULL;
    this->Bird_JumpStart = NULL;
    this->Bird_JumpEnd = NULL;
    this->PrimaryCommandedShout = NULL;
    this->SecondaryCommandedShout = NULL;
    this->Range = 5000.00f;
    this->DroneClass = NULL;
    this->RangeForReviveWithoutLineOfSight = 2000.00f;
    this->PlayerInputComponent = NULL;
    this->FPBirdMesh->SetupAttachment(RootComponent);
    this->TPBirdMesh->SetupAttachment(RootComponent);
}

void AAbilityDroneController::Server_UseSecondary_Implementation(FDroneControllerUseInfo droneInfo) {
}

void AAbilityDroneController::Server_UsePrimary_Implementation(FDroneControllerUseInfo droneInfo) {
}

void AAbilityDroneController::Server_ShowRecall_Implementation(bool sentOut) {
}

void AAbilityDroneController::Server_ShowActivation_Implementation(bool sentOut) {
}

void AAbilityDroneController::Server_RecallDrones_Implementation() {
}

void AAbilityDroneController::OnUsingFinished() {
}

void AAbilityDroneController::OnRep_DroneInstances() {
}

void AAbilityDroneController::OnDroneStateChanged(EAbilityDroneState State) {
}



void AAbilityDroneController::OnDroneDestroyed(AActor* drone) {
}

void AAbilityDroneController::OnDroneAttacked() {
}

void AAbilityDroneController::OnCharacterStateChanged(ECharacterState NewState) {
}

AActor* AAbilityDroneController::GetReviveTarget() const {
    return NULL;
}

void AAbilityDroneController::All_ShowRecall_Implementation(bool sentOut) {
}

void AAbilityDroneController::All_ShowActivation_Implementation(bool sentOut) {
}

void AAbilityDroneController::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const {
    Super::GetLifetimeReplicatedProps(OutLifetimeProps);
    
    DOREPLIFETIME(AAbilityDroneController, DroneInstances);
}


