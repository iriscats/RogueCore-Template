#include "MeleeSwipeItem.h"
#include "Components/AudioComponent.h"

AMeleeSwipeItem::AMeleeSwipeItem(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->SlicerSounds = CreateDefaultSubobject<UAudioComponent>(TEXT("SlicerSound"));
    this->CarveMesh = NULL;
    this->MagmaMaterial = NULL;
    this->HitEffect = NULL;
    this->BeamEffect = NULL;
    this->ImpactSound = NULL;
    this->SwipeHitConfirmSond = NULL;
    this->FP_AttackAnim = NULL;
    this->TP_AttackAnim = NULL;
    this->Damage = NULL;
    this->MinRange = 0.00f;
    this->MaxRange = 0.00f;
    this->Width = 100.00f;
    this->AttackThickness = 10.00f;
    this->AngleLimit = 90.00f;
    this->VerticalOffset = 0.00f;
    this->VerticalCarveOffset = 0.00f;
    this->ShowDebugBox = false;
    this->RequireFullyEquipped = true;
}

void AMeleeSwipeItem::Server_RegisterHits_Implementation(const FMeleeSwipeData& HitData) {
}

void AMeleeSwipeItem::Server_PerformSwipe_Implementation(FVector Origin, FVector carveOffset, FVector cameraDirection) {
}



void AMeleeSwipeItem::AttackAnimEnded() {
}

void AMeleeSwipeItem::All_ShowSwipe_Implementation(FVector Origin, FVector cameraDirection) {
}

void AMeleeSwipeItem::All_ShowHits_Implementation(const FMeleeSwipeData& HitData) {
}


