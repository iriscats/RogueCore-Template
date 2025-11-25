#include "FSDPlayerController.h"
#include "FSDCheatManager.h"
#include "FSDWidgetEffectsComponent.h"
#include "Net/UnrealNetwork.h"
#include "Templates/SubclassOf.h"
#include "TerrainLatejoinComponent.h"

AFSDPlayerController::AFSDPlayerController(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->CheatClass = UFSDCheatManager::StaticClass();
    this->ClickEventKeys.AddDefaulted(1);
    this->DebugEnemy = NULL;
    this->DebugEnemySpeed = -1.00f;
    this->DebugEnemySpeedMod = -1.00f;
    this->DebugEnemyLast = NULL;
    this->LateJoinComponent = CreateDefaultSubobject<UTerrainLatejoinComponent>(TEXT("TerrainLateJoin"));
    this->IsOnSpaceRig = false;
    this->ServerTravelDone = true;
    this->WidgetEffects = CreateDefaultSubobject<UFSDWidgetEffectsComponent>(TEXT("WidgetEffects"));
    this->SpacerigSpawnType = ESpacerigStartType::PlayerHub;
    this->bDetectGravityChanges = false;
    this->bReceivedEndLevel = false;
}

void AFSDPlayerController::ToggleVoiceOn(bool Enabled) {
}


void AFSDPlayerController::StartLevelEndSequence(const bool ShowEndScreen) {
}

void AFSDPlayerController::SpawnHUDLocal(TSubclassOf<AHUD> hudClass) {
}


void AFSDPlayerController::ShowTutorialWidget(TSubclassOf<UTutorialContentWidget> TutorialWidget, bool ignoreQueue) {
}

void AFSDPlayerController::ShowTutorialHint(const FText& Text, const FText& Title, const FText& TaskText, UTexture2D* Image, float Duration) {
}

void AFSDPlayerController::SetPlayerStart(AActor* Start) {
}

void AFSDPlayerController::SetAchievementProgressFromServer_Implementation(UFSDAchievement* AchievementToSet, float Progress) {
}

void AFSDPlayerController::ServerSetUserHoldToRun_Implementation(bool Value) {
}

void AFSDPlayerController::Server_TravelDone_Implementation() {
}

void AFSDPlayerController::Server_TakeDamageFrom_Implementation(UDamageComponent* Damage, FVector Location) {
}

void AFSDPlayerController::Server_StartNamedCountdownWithQuickFinish_Implementation(const FName Name, const int32 CountdownSeconds) {
}

void AFSDPlayerController::Server_StartNamedCountdown_Implementation(const FName Name, const int32 CountdownSeconds) {
}

void AFSDPlayerController::Server_SetLateJoinDone_Implementation() {
}

void AFSDPlayerController::Server_SetGenerationStatus_Implementation(const FString& status, float Fraction) {
}

void AFSDPlayerController::Server_SetGenerationFraction_Implementation(float Fraction) {
}

void AFSDPlayerController::Server_SetGenerationDone_Implementation() {
}

void AFSDPlayerController::Server_SetDebugEnemy_Implementation(ADeepPathfinderCharacter* NewDebugEnemy) {
}

void AFSDPlayerController::Server_SetControllerReady_Implementation() {
}

void AFSDPlayerController::Server_ResetNamedCountdown_Implementation(const FName Name) {
}

void AFSDPlayerController::Server_ResetHUD_Implementation() {
}

void AFSDPlayerController::Server_Relay_SetArmorIndexDestroyed_Implementation(USimpleArmorDamageComponent* ArmorComponent, int32 Index, EArmorDamageType DamageType) {
}

void AFSDPlayerController::Server_ReceiveClientRadialDamageRapport_Implementation(const FClientRadialDamageRapport& rapport) {
}

void AFSDPlayerController::Server_ReceiveClientDamageRapport_Implementation(const FClientDamageRapport& rapport) {
}

void AFSDPlayerController::Server_NewMessage_Implementation(const FString& Sender, const FString& Text, EChatSenderType SenderType) {
}

void AFSDPlayerController::Server_DrawProjectileDebugPath_Implementation(bool bDraw) {
}

bool AFSDPlayerController::Server_DrawProjectileDebugPath_Validate(bool bDraw) {
    return true;
}

bool AFSDPlayerController::Server_NewMessage_Validate(const FString& Sender, const FString& Text, EChatSenderType SenderType) {
    return true;
}

bool AFSDPlayerController::Server_ReceiveClientDamageRapport_Validate(const FClientDamageRapport& rapport) {
    return true;
}

bool AFSDPlayerController::Server_ReceiveClientRadialDamageRapport_Validate(const FClientRadialDamageRapport& rapport) {
    return true;
}

bool AFSDPlayerController::Server_Relay_SetArmorIndexDestroyed_Validate(USimpleArmorDamageComponent* ArmorComponent, int32 Index, EArmorDamageType DamageType) {
    return true;
}

bool AFSDPlayerController::Server_ResetHUD_Validate() {
    return true;
}

bool AFSDPlayerController::Server_ResetNamedCountdown_Validate(const FName Name) {
    return true;
}

bool AFSDPlayerController::Server_SetControllerReady_Validate() {
    return true;
}

bool AFSDPlayerController::Server_SetDebugEnemy_Validate(ADeepPathfinderCharacter* NewDebugEnemy) {
    return true;
}

bool AFSDPlayerController::Server_SetGenerationDone_Validate() {
    return true;
}

bool AFSDPlayerController::Server_SetGenerationFraction_Validate(float Fraction) {
    return true;
}

bool AFSDPlayerController::Server_SetGenerationStatus_Validate(const FString& status, float Fraction) {
    return true;
}

bool AFSDPlayerController::Server_SetLateJoinDone_Validate() {
    return true;
}

bool AFSDPlayerController::Server_StartNamedCountdown_Validate(const FName Name, const int32 CountdownSeconds) {
    return true;
}

bool AFSDPlayerController::Server_StartNamedCountdownWithQuickFinish_Validate(const FName Name, const int32 CountdownSeconds) {
    return true;
}

bool AFSDPlayerController::Server_TakeDamageFrom_Validate(UDamageComponent* Damage, FVector Location) {
    return true;
}

bool AFSDPlayerController::Server_TravelDone_Validate() {
    return true;
}

void AFSDPlayerController::SendLevelUpStatistics(const int32 currentRank) {
}





void AFSDPlayerController::OnSaveGamePlayerProgressChanged(int32 Rank, int32 Stars) {
}

void AFSDPlayerController::OnSaveGameCreditsChanged(int32 Credits) {
}

void AFSDPlayerController::OnSaveGameCharacterProgressChanged(TSubclassOf<APlayerCharacter> CharacterClass, int32 Level, float Progress) {
}

void AFSDPlayerController::OnRep_DebugEnemyLocation() {
}

void AFSDPlayerController::OnPlayerStateSelectedCharacterChanged(TSubclassOf<APlayerCharacter> CharacterClass) {
}


void AFSDPlayerController::OnLevelEnd_Implementation() {
}


void AFSDPlayerController::HideTutorialHint(bool watched) {
}

bool AFSDPlayerController::GetUseToggleTerrainScanner() {
    return false;
}

bool AFSDPlayerController::GetUseToggleLaserPointer() {
    return false;
}

bool AFSDPlayerController::GetUseHoldToRun() {
    return false;
}

AActor* AFSDPlayerController::GetPlayerStart() {
    return NULL;
}

AFSDPlayerState* AFSDPlayerController::GetFSDPlayerState() const {
    return NULL;
}

bool AFSDPlayerController::GetEndLevelFlagSet() const {
    return false;
}

EAbilityActivationMode AFSDPlayerController::GetAbilityActivationMode() {
    return EAbilityActivationMode::Contextual;
}

void AFSDPlayerController::FlushRender() {
}

AActor* AFSDPlayerController::FindPlayerStart(UPlayerCharacterID* characterID) {
    return NULL;
}

void AFSDPlayerController::Client_PlayCue_Implementation(USoundCue* SoundCue) {
}

void AFSDPlayerController::Client_CollectVanityItem_Implementation(UTreasureRewarder* rewarder, UVanityItem* targetItem, UPlayerCharacterID* targetCharacter) {
}

void AFSDPlayerController::Client_CollectTreasureVictoryPose_Implementation(UTreasureRewarder* rewarder, UVictoryPose* targetPose, UPlayerCharacterID* targetCharacter) {
}

void AFSDPlayerController::Client_CollectTreasureSkin_Implementation(USkinTreasureRewarder* rewarder, UItemSkin* targetSkin, UItemID* targetItem) {
}

void AFSDPlayerController::Client_CollectPickaxePart_Implementation(const UTreasureRewarder* rewarder, UPickaxePart* targetPart) {
}

void AFSDPlayerController::ApplyLevelEndResultsAndNotifyServer() {
}

void AFSDPlayerController::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const {
    Super::GetLifetimeReplicatedProps(OutLifetimeProps);
    
    DOREPLIFETIME(AFSDPlayerController, DebugEnemy);
    DOREPLIFETIME(AFSDPlayerController, DebugEnemyLocation);
    DOREPLIFETIME(AFSDPlayerController, DebugEnemySpeed);
    DOREPLIFETIME(AFSDPlayerController, DebugEnemySpeedMod);
}


