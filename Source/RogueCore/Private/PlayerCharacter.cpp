#include "PlayerCharacter.h"
#include "Camera/CameraComponent.h"
#include "Runtime/Engine/Classes/Components/PointLightComponent.h"
#include "Components/SceneComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "Components/WidgetInteractionComponent.h"
#include "AccessCollectionComponent.h"
#include "ActorTrackingComponent.h"
#include "BXEStatCounterComponent.h"
#include "BoosterDeckContainerComponent.h"
#include "CharacterCameraController.h"
#include "CharacterRecoilComponent.h"
#include "CharacterSightComponent.h"
#include "CharacterUseComponent.h"
#include "CharacterVanityComponent.h"
#include "CommunicationComponent.h"
#include "CrosshairExtensionComponent.h"
#include "DamageNumberAggregator.h"
#include "ElementComponent.h"
#include "FSDPlayerCheatComponent.h"
#include "FirstPersonSkeletalMeshComponent.h"
#include "InstantUsable.h"
#include "InventoryComponent.h"
#include "MissionStatsCollector.h"
#include "Net/UnrealNetwork.h"
#include "OutlineComponent.h"
#include "PawnStatsComponent.h"
#include "PerkComponent.h"
#include "PlayerAfflictionComponent.h"
#include "PlayerAmbienceSoundComponent.h"
#include "PlayerAttackPositionComponent.h"
#include "PlayerEventsComponent.h"
#include "PlayerHealthComponent.h"
#include "PlayerInfoComponent.h"
#include "PlayerMovementComponent.h"
#include "PlayerReactiveTerrainTrackerComponent.h"
#include "SingleUsableComponent.h"
#include "StatusEffectsComponent.h"
#include "Templates/SubclassOf.h"
#include "UpgradeContainerComponent.h"
#include "WeaponTagBonusesComponent.h"

APlayerCharacter::APlayerCharacter(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer.SetDefaultSubobjectClass<UPlayerMovementComponent>(TEXT("CharMoveComp"))) {

}

void APlayerCharacter::UseZipLine(AZipLineProjectile* ZipLine, const FVector& Start, const FVector& End) {
}

void APlayerCharacter::Unparalyze() {
}

void APlayerCharacter::TryUseInstantRevive(APlayerCharacter* ReviveTarget) {
}

bool APlayerCharacter::TryFreezeCharacter(UElementType* ElementType, UElementEventType* ElementEventTrigger) {
    return false;
}

void APlayerCharacter::ToggleHUDReleased() {
}

void APlayerCharacter::ToggleHUDPressed() {
}

void APlayerCharacter::ToggleHeadLight() {
}

void APlayerCharacter::ThrowFlareReleased() {
}

void APlayerCharacter::ThrowFlarePressed() {
}

void APlayerCharacter::ThrowFlare() {
}

void APlayerCharacter::StopUsingItem() {
}

void APlayerCharacter::StartTutorials(bool ResetTutorials) {
}

void APlayerCharacter::StartPerkActivation(UPerkActivationWidget* PerkActivationWidget, float HoldTime) {
}

UAudioComponent* APlayerCharacter::SpawnSoundAttached(USoundBase* Sound, USceneComponent* AttachToComponent, float PriorityOverride, FName AttachPointName, FVector Location, FRotator Rotation, TEnumAsByte<EAttachLocation::Type> LocationType, bool bStopWhenAttachedToDestroyed, float VolumeMultiplier, float PitchMultiplier, float StartTime, USoundAttenuation* AttenuationSettings, USoundConcurrency* ConcurrencySettings, USoundClass* soundClassOverride, bool bAutoDestroy, bool SendVibration) {
    return NULL;
}

UAudioComponent* APlayerCharacter::SpawnSoundAtLocation(USoundBase* Sound, FVector Location, FRotator Rotation, float VolumeMultiplier, float PitchMultiplier, float StartTime, USoundAttenuation* AttenuationSettings, USoundConcurrency* ConcurrencySettings, bool bAutoDestroy, bool SendVibration) {
    return NULL;
}

UAudioComponent* APlayerCharacter::SpawnSound2D(USoundBase* Sound, float PriorityOverride, float VolumeMultiplier, float PitchMultiplier, float StartTime, USoundConcurrency* ConcurrencySettings, bool bPersistAcrossLevelTransition, bool bAutoDestroy, bool SendVibration) {
    return NULL;
}

void APlayerCharacter::ShowSimpleHoldProgress(APlayerController* PlayerController, const FText& InDescription, float InProgress) {
}

void APlayerCharacter::SetStandingDown(bool standingDown) {
}

void APlayerCharacter::SetRadarMaterialInstance(UMaterialInstanceDynamic* matInstance) {
}

void APlayerCharacter::SetPlayerResource(UResourceData* Resource, float amount) {
}

void APlayerCharacter::SetOutsideShieldGenerator(AShieldGeneratorActor* Shield) {
}

void APlayerCharacter::SetIsCharacterSelectionModel() {
}

void APlayerCharacter::SetInstantUsables_Implementation(bool Value) {
}

void APlayerCharacter::SetInsideShieldGenerator(AShieldGeneratorActor* Shield) {
}

void APlayerCharacter::SetInCharacterSelectionWorld() {
}

void APlayerCharacter::SetHeadLight_Implementation(bool On) {
}

void APlayerCharacter::SetFallbackPhysicalMaterial(UFSDPhysicalMaterial* PhysMat) {
}

void APlayerCharacter::SetCameraMode(ECharacterCameraMode newCameraMode) {
}

void APlayerCharacter::SetAvailableAirJumps(int32 InAmount) {
}

void APlayerCharacter::SetAttached(USceneComponent* AttachTo, bool DelayUntilLanded) {
}

void APlayerCharacter::Server_TriggerDash_Implementation() {
}

void APlayerCharacter::Server_TestGenerationDesync_Implementation() {
}

void APlayerCharacter::Server_StartSalute_Implementation(UAnimMontage* startSalute) {
}

void APlayerCharacter::Server_SpawnEnemies_Implementation(UEnemyDescriptor* descriptor, int32 count) {
}

void APlayerCharacter::Server_Shouted_Implementation() {
}

void APlayerCharacter::Server_SetUsing_Implementation(bool characterIsUsing) {
}

void APlayerCharacter::Server_SetRunning_Implementation(bool characterIsRunning) {
}

void APlayerCharacter::Server_SetRunBoostActive_Implementation(bool IsActive) {
}

void APlayerCharacter::Server_SetIsThrowingCarriable_Implementation(bool isThrowing) {
}

void APlayerCharacter::Server_SetIsPressingMovementInput_Implementation(bool aIsPushingInput) {
}

void APlayerCharacter::Server_SetIsJumpPressed_Implementation(bool InJumpPressed) {
}

void APlayerCharacter::Server_SetDispenserReward_Implementation(ARewardDispenserBase* Dispenser, UDataAsset* Reward) {
}

void APlayerCharacter::Server_SetClientReady_Implementation() {
}

void APlayerCharacter::Server_InstantRevive_Implementation(APlayerCharacter* ReviveTarget, EInputKeys Key) {
}

void APlayerCharacter::Server_GenerationDesyncDataRecieved_Implementation(const FTestGenerationPacket& InClientPacket) {
}

void APlayerCharacter::Server_EscapeFromGrabber_Implementation() {
}

void APlayerCharacter::Server_ClearBiomeEffects_Implementation() {
}

void APlayerCharacter::Server_CheatRevive_Implementation() {
}

void APlayerCharacter::Server_CheatKillAllFriendly_Implementation() {
}

void APlayerCharacter::Server_CheatKillAll_Implementation() {
}

void APlayerCharacter::Server_CheatJetBoots_Implementation() {
}

void APlayerCharacter::Server_CheatGodMode_Implementation() {
}

void APlayerCharacter::Server_CheatFlyMode_Implementation(bool Active) {
}

void APlayerCharacter::Server_CheatDebugFastMode_Implementation(bool fast) {
}

void APlayerCharacter::Server_CheatAddAllResourcesToInventory_Implementation(float amount) {
}

void APlayerCharacter::Server_CancelThrowingCarriable_Implementation() {
}

void APlayerCharacter::Server_CallDonkey_Implementation() {
}

void APlayerCharacter::Server_BiomeEffectsEnabled_Implementation(bool Enabled) {
}

void APlayerCharacter::Server_AddToTraceQueue_Implementation(ADamageEnhancer* Target, FEnhancedTrace Item) {
}

void APlayerCharacter::Server_AddImpulseToActor_Implementation(AFSDPhysicsActor* Target, FVector_NetQuantize Impulse, FVector_NetQuantize Location, FVector_NetQuantize AngularImpulse) {
}

void APlayerCharacter::Server_AddImpulse_Implementation(const FVector_NetQuantizeNormal& Direction, float Force) {
}

void APlayerCharacter::Server_ActivateTemporaryBuff_Implementation(UTemporaryBuff* buff) {
}

void APlayerCharacter::ReviveProgress(float Progress) {
}

void APlayerCharacter::RevivePlayer() {
}

void APlayerCharacter::RequestChangeInGravityScale_Implementation(float newGravityScale) {
}

void APlayerCharacter::RemoveRunningBoostEffects(TArray<TSubclassOf<UStatusEffect>> effects) {
}

void APlayerCharacter::RemoveRunningBoostEffect(TSubclassOf<UStatusEffect> Effect) {
}

void APlayerCharacter::RemoveCloseFlare() {
}

void APlayerCharacter::RejectInvite() {
}




void APlayerCharacter::QuickUseGeneral(const int32 Index) {
}


void APlayerCharacter::PilotVehicle(AActor* Vehicle) {
}

void APlayerCharacter::Paralyze(AActor* ParalyzedBy) {
}

void APlayerCharacter::OpenChat() {
}

void APlayerCharacter::OnResourceFull(UCappedResource* Resource) {
}

void APlayerCharacter::OnRep_UniqueRunID() {
}

void APlayerCharacter::OnRep_IsStandingDown() {
}

void APlayerCharacter::OnRep_IsDancing() {
}

void APlayerCharacter::OnRep_IsCloseToFlare(bool prevCloseToFlare) {
}

void APlayerCharacter::OnRep_HeadLightOn() {
}

void APlayerCharacter::OnRep_DanceMove() {
}

void APlayerCharacter::OnRep_CharacterState(UCharacterStateComponent* oldState) {
}

//void APlayerCharacter::OnPlayerStateChanged(const APlayerCharacter::FOnPlayerStateDelegate& OnNewStateSet, bool CallInstantlyIfAlreadySet) {
//}

void APlayerCharacter::OnItemEquipped(AItem* Item) {
}

void APlayerCharacter::OnCharacterUsed(APlayerCharacter* User, EInputKeys Key) {
}

void APlayerCharacter::OnCharacterEndUse() {
}

void APlayerCharacter::OnCharacterBeginUse(APlayerCharacter* User, EInputKeys Key) {
}

void APlayerCharacter::OnAbilityDeactivated() {
}

void APlayerCharacter::MouseWheelUp() {
}

void APlayerCharacter::MouseWheelDown() {
}

void APlayerCharacter::JumpRelease() {
}

void APlayerCharacter::JumpPress() {
}

bool APlayerCharacter::IsWithinDistance(AActor* Source, float Distance) const {
    return false;
}

bool APlayerCharacter::IsWalking() const {
    return false;
}

bool APlayerCharacter::IsUsingPressed() const {
    return false;
}

bool APlayerCharacter::IsUsingItemPressed() const {
    return false;
}

bool APlayerCharacter::IsSuspended() const {
    return false;
}

bool APlayerCharacter::IsStateActive(ECharacterState State) const {
    return false;
}

bool APlayerCharacter::IsSaluting() const {
    return false;
}

bool APlayerCharacter::IsParalyzed() const {
    return false;
}

bool APlayerCharacter::IsMovementInputPressed() {
    return false;
}

bool APlayerCharacter::IsMining() const {
    return false;
}

bool APlayerCharacter::IsLyingDown() const {
    return false;
}

bool APlayerCharacter::IsJumpPressed() const {
    return false;
}

bool APlayerCharacter::IsInState(ECharacterState aState) const {
    return false;
}

bool APlayerCharacter::IsIncapacitated() const {
    return false;
}

bool APlayerCharacter::IsFrozen() const {
    return false;
}

bool APlayerCharacter::IsFirstPerson() const {
    return false;
}

bool APlayerCharacter::IsEquipepdActor(AActor* Actor) const {
    return false;
}

bool APlayerCharacter::IsDown() const {
    return false;
}

bool APlayerCharacter::IsBuried() const {
    return false;
}

bool APlayerCharacter::IsAlive() const {
    return false;
}

void APlayerCharacter::InvalidateTeleport_Implementation() {
}

void APlayerCharacter::InstantRevive(APlayerCharacter* ReviveTarget, EInputKeys Key) {
}

void APlayerCharacter::IgnoreInvite() {
}

bool APlayerCharacter::HasBeenRevived() const {
    return false;
}

UCharacterUseComponent* APlayerCharacter::GetUseComponent() const {
    return NULL;
}

UPlayerTPAnimInstance* APlayerCharacter::GetTPAnimInstance() const {
    return NULL;
}

float APlayerCharacter::GetTimeSinceLastRevival() const {
    return 0.0f;
}

ECharacterState APlayerCharacter::GetPreviousState() const {
    return ECharacterState::Walking;
}

AFSDPlayerState* APlayerCharacter::GetPlayerState() const {
    return NULL;
}

FString APlayerCharacter::GetPlayerName() const {
    return TEXT("");
}

UPlayerEventsComponent* APlayerCharacter::GetPlayerEvents() const {
    return NULL;
}

float APlayerCharacter::GetPlayerDirectionAngle() const {
    return 0.0f;
}

AFSDPlayerController* APlayerCharacter::GetPlayerController() const {
    return NULL;
}

UInventoryList* APlayerCharacter::GetInventoryList() const {
    return NULL;
}

FText APlayerCharacter::GetHeroSwitchToMessage() const {
    return FText::GetEmpty();
}

FText APlayerCharacter::GetHeroName() const {
    return FText::GetEmpty();
}

FHeroInfo APlayerCharacter::GetHeroInfo() const {
    return FHeroInfo{};
}

UTexture2D* APlayerCharacter::GetHeroIcon() const {
    return NULL;
}

FLinearColor APlayerCharacter::GetHeroColor() const {
    return FLinearColor{};
}

UPlayerFPAnimInstance* APlayerCharacter::GetFPAnimInstance() const {
    return NULL;
}

AItem* APlayerCharacter::GetEquippedItem() const {
    return NULL;
}

float APlayerCharacter::GetDownTime() const {
    return 0.0f;
}

APlayerCharacter* APlayerCharacter::GetDownCameraTarget() const {
    return NULL;
}




ECharacterState APlayerCharacter::GetCurrentState() const {
    return ECharacterState::Walking;
}

UCommunicationComponent* APlayerCharacter::GetCommunicationComponent() const {
    return NULL;
}

float APlayerCharacter::GetClassXP() {
    return 0.0f;
}

UCharacterVanityComponent* APlayerCharacter::GetCharacterVanity() const {
    return NULL;
}

UCharacterStateComponent* APlayerCharacter::GetCharacterStateComponent(ECharacterState State) const {
    return NULL;
}

UBXEStatCounterComponent* APlayerCharacter::GetBXEStatCounterComponent() const {
    return NULL;
}

UBoosterDeckContainerComponent* APlayerCharacter::GetBoosterDeckContainerComponent() const {
    return NULL;
}

float APlayerCharacter::GetBeginRevivedProgress() const {
    return 0.0f;
}


FString APlayerCharacter::GetAnalyticsClass() const {
    return TEXT("");
}

FRotator APlayerCharacter::GetAimRotation() const {
    return FRotator{};
}

FVector APlayerCharacter::GetActorGroundLocation() const {
    return FVector{};
}

TArray<AShieldGeneratorActor*> APlayerCharacter::GetActiveShieldGenerators() {
    return TArray<AShieldGeneratorActor*>();
}

UPlayerAnimInstance* APlayerCharacter::GetActiveAnimInstance() const {
    return NULL;
}

UAbilityData* APlayerCharacter::GetAbilityData(APlayerCharacter* InCharacter) {
    return NULL;
}

UAbilityComponent* APlayerCharacter::GetAbilityComponent() const {
    return NULL;
}

void APlayerCharacter::ForceIsPressingMovementInputKey() {
}

void APlayerCharacter::ExitVehicle() {
}

void APlayerCharacter::CycleItemUp() {
}

void APlayerCharacter::CycleItemReleased() {
}

void APlayerCharacter::CycleItemPressed() {
}

void APlayerCharacter::CycleItemDown() {
}

void APlayerCharacter::ConsumeCycleItemButton() {
}

void APlayerCharacter::Client_TestGenerationDesync_Implementation() {
}

void APlayerCharacter::Client_OpenMinersManual_Implementation() {
}

void APlayerCharacter::Client_AddImpulse_Implementation(const FVector_NetQuantizeNormal& Direction, float Force) {
}

void APlayerCharacter::Client_ActivateTemporaryBuff_Implementation(UTemporaryBuff* buff) {
}

void APlayerCharacter::ChangeState(ECharacterState NewState) {
}

void APlayerCharacter::ChangeIfDifferentState(ECharacterState NewState) {
}

bool APlayerCharacter::CanEscapeFromGrabber() const {
    return false;
}

void APlayerCharacter::CallDonkeyReleased() {
}

void APlayerCharacter::CallDonkeyPressed() {
}



void APlayerCharacter::AnnounceSchematicCollected(USchematic* InSchematic) {
}

void APlayerCharacter::All_StartSalute_Implementation(UAnimMontage* saluteMontage) {
}

void APlayerCharacter::All_ShowImpactEffects_Implementation(UFXSystemAsset* Particles, FVector_NetQuantize Location, FVector_NetQuantizeNormal Orientation) const {
}

void APlayerCharacter::All_ShowFieldMedicInstantReviveEffects_Implementation() {
}

void APlayerCharacter::All_PlayCompletedUseMontage_Implementation(UUseAnimationSetting* useSetting) {
}

void APlayerCharacter::All_OnCharacterUsedAirJump_Implementation(APlayerCharacter* InPlayer) {
}

void APlayerCharacter::AddRunningBoostEffects(TArray<TSubclassOf<UStatusEffect>> effects) {
}

void APlayerCharacter::AddRunningBoostEffect(TSubclassOf<UStatusEffect> Effect) {
}

void APlayerCharacter::AddPlayerResource(UResourceData* Resource, float amount) {
}

void APlayerCharacter::AddImpulseToActor(AFSDPhysicsActor* Target, FVector_NetQuantize Impulse, FVector_NetQuantize Location, FVector_NetQuantize AngularImpulse) {
}

void APlayerCharacter::AddImpulseFromVector(const FVector& Vector) {
}

void APlayerCharacter::AddImpulseFromDirectionAndForce(const FVector& Direction, float Force) {
}

void APlayerCharacter::AddCloseFlare() {
}

void APlayerCharacter::AcknowledgeCharacterState_Implementation(ECharacterState eState) {
}

void APlayerCharacter::AcceptInvite() {
}

void APlayerCharacter::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const {
    Super::GetLifetimeReplicatedProps(OutLifetimeProps);

    DOREPLIFETIME(APlayerCharacter, IsCloseToFlare);
    DOREPLIFETIME(APlayerCharacter, IsPressingMovementInputKey);
    DOREPLIFETIME(APlayerCharacter, ActiveCharacterState);
    DOREPLIFETIME(APlayerCharacter, IsRunning);
    DOREPLIFETIME(APlayerCharacter, bIsWorkingout);
    DOREPLIFETIME(APlayerCharacter, HeadLightOn);
    DOREPLIFETIME(APlayerCharacter, isUsing);
    DOREPLIFETIME(APlayerCharacter, IsStandingDown);
    DOREPLIFETIME(APlayerCharacter, IsDancing);
    DOREPLIFETIME(APlayerCharacter, DanceMove);
    DOREPLIFETIME(APlayerCharacter, PlayerIsLeavingInDroppod);
    DOREPLIFETIME(APlayerCharacter, UniqueRunID);
}



