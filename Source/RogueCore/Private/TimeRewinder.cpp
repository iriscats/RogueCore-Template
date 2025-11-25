#include "TimeRewinder.h"

ATimeRewinder::ATimeRewinder(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->FoVModulation = NULL;
    this->ActivationSound = NULL;
    this->AciveSoundLoop = NULL;
    this->DeactivateSound = NULL;
    this->Item_SaveRewindPoint = NULL;
    this->Item_RewindToPoint = NULL;
    this->Item_Equip_Active = NULL;
    this->FP_Equip_Active = NULL;
    this->FP_RewindToPoint = NULL;
    this->TP_Equip_Active = NULL;
    this->TP_Recall = NULL;
    this->PostProcessMaterial = NULL;
    this->ActiveOverlayMaterial = NULL;
    this->TP_ActiveOverlayMaterial = NULL;
    this->ActiveTrail = NULL;
    this->HologramClass = NULL;
    this->ActiveAnimationSet = NULL;
    this->WarntAtTimeRemaining = 1.00f;
    this->TimePerChargeDrain = 30.00f;
    this->RewindDelay = 0.00f;
}

void ATimeRewinder::Terminate() {
}

void ATimeRewinder::Server_ShowTPRecall_Implementation() {
}

void ATimeRewinder::Server_ShowTPActivation() {
}

//void ATimeRewinder::Server_SavedRewindSpot_Implementation(FRewindData Data) {
//}

//void ATimeRewinder::Server_RewindStarted(FRewindData Data) {
//}

//void ATimeRewinder::Server_Rewind(FRewindData Data) {
//}

void ATimeRewinder::Server_DeactivateEffects() {
}




void ATimeRewinder::OnDeath(UHealthComponentBase* Health) {
}

void ATimeRewinder::InvalidatePositioningAbilities() {
}

float ATimeRewinder::GetTimeLimitRemainingPct() const {
    return 0.0f;
}

void ATimeRewinder::DrainTick() {
}

void ATimeRewinder::DeactivateAfterRewind() {
}

void ATimeRewinder::All_ShowTPRecall_Implementation() {
}

void ATimeRewinder::All_ShowTPActivation() {
}

void ATimeRewinder::All_OnDeath_Implementation() {
}

void ATimeRewinder::All_DeactivateEffects() {
}


