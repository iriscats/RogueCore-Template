#include "AmmoDrivenWeapon.h"
#include "AmmoDriveWeaponAggregator.h"
#include "Net/UnrealNetwork.h"
#include "WeaponTagContainerComponent.h"

AAmmoDrivenWeapon::AAmmoDrivenWeapon(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->WeaponTags = CreateDefaultSubobject<UWeaponTagContainerComponent>(TEXT("WeaponTags"));
    this->WeaponFire = NULL;
    this->Aggregator = CreateDefaultSubobject<UAmmoDriveWeaponAggregator>(TEXT("Aggregator"));
    this->LoopFireAnimation = false;
    this->OverHeatOnNoAmmo = false;
    this->LoopFireAnimationBlendoutTime = 0.25f;
    this->FP_FireAnimation = NULL;
    this->TP_FireAnimation = NULL;
    this->FP_ReloadAnimation = NULL;
    this->FP_ReloadAnimation_Empty = NULL;
    this->TP_ReloadAnimation = NULL;
    this->TP_ReloadAnimation_Empty = NULL;
    this->WPN_Fire = NULL;
    this->WPN_FireLastBullet = NULL;
    this->WPN_Reload = NULL;
    this->WPN_ReloadEmpty = NULL;
    this->WPN_Reload_TP = NULL;
    this->MuzzleParticles = NULL;
    this->TPMuzzleParticles = NULL;
    this->UseTriggeredMuzzleParticles = false;
    this->CasingParticles = NULL;
    this->UseTriggeredCasingParticleSystem = false;
    this->MuzzleFlashLight = NULL;
    this->FireSound = NULL;
    this->RicochetSound = NULL;
    this->RicochetParticle = NULL;
    this->FireSoundDelayToTail = -1.00f;
    this->FireSoundTail = NULL;
    this->IsFireSoundTail2D = false;
    this->FireForceFeedbackEffect = NULL;
    this->FireSoundFadeDuration = 0.20f;
    this->ReloadSound = NULL;
    this->BulletsRemainingForNearEmptySound = 0;
    this->BulletsRemainingNearEmptyVolumeCurve = NULL;
    this->PlayNearEmptySoundsIn3D = false;
    this->PlayClipReachesZeroSoundsIn3D = true;
    this->PlayEmptySoundsIn3D = true;
    this->NearEmptySound = NULL;
    this->ClipReachesZeroSound = NULL;
    this->DryFireSound = NULL;
    this->ShoutShotFired = NULL;
    this->ShoutOutOfAmmo = NULL;
    this->ShoutReloading = NULL;
    this->MaxAmmo = 0;
    this->ClipSize = 0;
    this->ShotCost = 1;
    this->RateOfFire = 0.00f;
    this->BurstCount = 0;
    this->BurstCycleTime = 20.00f;
    this->ReloadDuration = 0.00f;
    this->ShouldInitAmmoAtBeginPlay = true;
    this->ManualHeatReductionAmmo = 0;
    this->FireInputBufferTime = 0.00f;
    this->AutoReloadDuration = 0.00f;
    this->AutoReloadCompleteCue = NULL;
    this->SupplyStatusWeight = 1.00f;
    this->CycleTimeLeft = 0.00f;
    this->UseCustomReloadDelay = false;
    this->CustomReloadDelay = 0.00f;
    this->ReloadTimeLeft = 0.00f;
    this->AutomaticReload = false;
    this->CanReload = false;
    this->HoldToFirePercentOfFireRatePenalty = -1.00f;
    this->ApplyRecoilAtEndOfBurst = false;
    this->EndOfBurstRecoilMultiplier = 1.00f;
    this->HasAutomaticFire = false;
    this->IsFiring = false;
    this->OverheatOnReload = false;
    this->ManualHeatReductionOnReload = false;
    this->MaxManualHeatReductionCharges = 0;
    this->ManualHeatReductionValue = 0.00f;
    this->CanManuallyReload = true;
    this->WeaponState = EAmmoWeaponState::Equipping;
    this->HasRejoinedInitialized = false;
}


void AAmmoDrivenWeapon::UpdateHoldToFire() {
}

void AAmmoDrivenWeapon::TransferAmmoToClip(int32 amount) {
}

void AAmmoDrivenWeapon::Server_UpdateClipCount_Implementation(const FAmmoValue& Val) {
}

void AAmmoDrivenWeapon::Server_UpdateAmmoCount_Implementation(const FAmmoValue& Val) {
}

void AAmmoDrivenWeapon::Server_StopReload_Implementation(float blendOutTime) {
}

void AAmmoDrivenWeapon::Server_ReloadWeapon_Implementation(bool isFullyEmpty) {
}

void AAmmoDrivenWeapon::Server_PlayWeaponEmptySound_3D_Implementation() {
}

void AAmmoDrivenWeapon::Server_PlayBurstFire_Implementation(uint8 shotCount) {
}

void AAmmoDrivenWeapon::Server_Gunsling_Implementation(uint8 Index) {
}

void AAmmoDrivenWeapon::ResupplyToPercent(float percentage) {
}

void AAmmoDrivenWeapon::ResupplyAmmo(int32 amount) {
}





void AAmmoDrivenWeapon::OnWeaponFireEnded() {
}

void AAmmoDrivenWeapon::OnWeaponFired(const FVector& Location) {
}

void AAmmoDrivenWeapon::OnTagBonusChanged() {
}

void AAmmoDrivenWeapon::OnRicochet(const FVector& Origin, const FVector& Location, const FVector& Normal) {
}

void AAmmoDrivenWeapon::OnRep_ReserveCount() {
}

void AAmmoDrivenWeapon::OnRep_IsFiring() {
}

void AAmmoDrivenWeapon::OnRep_ClipCount() {
}

void AAmmoDrivenWeapon::MoveAmmoFromReserve(int32 amount) {
}

void AAmmoDrivenWeapon::MoveAmmoBackToReserve(int32 amount) {
}

bool AAmmoDrivenWeapon::IsClipFull() const {
    return false;
}

void AAmmoDrivenWeapon::InstantlyReload() {
}

void AAmmoDrivenWeapon::InitAmmo() {
}


void AAmmoDrivenWeapon::Client_SetAmmoScalePercent_Implementation(float Percent) {
}

void AAmmoDrivenWeapon::Client_SetAmmo_Implementation(float percentage) {
}

void AAmmoDrivenWeapon::Client_ResupplyAmmo_Implementation(int32 count) {
}

void AAmmoDrivenWeapon::Client_RefillAmmo_Implementation(float percentage) {
}

void AAmmoDrivenWeapon::All_StopReload_Implementation(float blendOutTime) {
}

void AAmmoDrivenWeapon::All_StartReload_Implementation(bool isFullyEmpty) {
}

void AAmmoDrivenWeapon::All_PlayWeaponEmptySound_3D_Implementation() {
}

void AAmmoDrivenWeapon::All_PlayBurstFire_Implementation(uint8 shotCount) {
}

void AAmmoDrivenWeapon::All_Gunsling_Implementation(uint8 Index) {
}

void AAmmoDrivenWeapon::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const {
    Super::GetLifetimeReplicatedProps(OutLifetimeProps);
    
    DOREPLIFETIME(AAmmoDrivenWeapon, FP_ReloadAnimation);
    DOREPLIFETIME(AAmmoDrivenWeapon, FP_ReloadAnimation_Empty);
    DOREPLIFETIME(AAmmoDrivenWeapon, TP_ReloadAnimation);
    DOREPLIFETIME(AAmmoDrivenWeapon, WPN_Reload);
    DOREPLIFETIME(AAmmoDrivenWeapon, ReserveCount);
    DOREPLIFETIME(AAmmoDrivenWeapon, ClipCount);
    DOREPLIFETIME(AAmmoDrivenWeapon, ShouldInitAmmoAtBeginPlay);
    DOREPLIFETIME(AAmmoDrivenWeapon, ManualHeatReductionAmmo);
    DOREPLIFETIME(AAmmoDrivenWeapon, IsFiring);
    DOREPLIFETIME(AAmmoDrivenWeapon, HasRejoinedInitialized);
}


