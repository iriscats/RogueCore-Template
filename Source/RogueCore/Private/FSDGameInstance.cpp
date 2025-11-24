#include "FSDGameInstance.h"
#include "FSDSendToURL.h"
#include "Templates/SubclassOf.h"

UFSDGameInstance::UFSDGameInstance() {
    this->GameDataClass = NULL;
    this->ShowingReconnectScreen = false;
    this->ProceduralSetup = NULL;
    this->HasStartedAMission = false;
    this->CanPlayOnline = true;
    this->FirstTimeInFrontend = true;
    this->SessionFirstStartOnSpaceRig = true;
    this->ShowFirstCharacterSelector = true;
    this->ShowSaveWarning = true;
    this->WorldViewTargetDummy = NULL;
    this->MissionResultInfo = NULL;
    this->LoaderSequencePlaying = false;
    this->CharacterSelectionLastViewTarget = NULL;
    this->HasSeenInfoScreen = false;
    this->DEBUGRandomGlobalMissionSeedEnabled = false;
    this->DEBUGRandomGlobalMissionSeed = -1;
    this->DEBUGFixedGlobalMissionSeed = -1;
    this->DEBUGFixedPLSSeed = -1;
    this->CanCommunicateOnline = true;
    this->FXTelemetry = NULL;
    this->ForcedMachineEvent = NULL;
    this->ForcedOtherEvent = NULL;
    this->ShowMinerManualWorkInProgress = false;
    this->LastDreadnaughtKillTime = -1.00f;
    this->CharacterSelectionSwitcher = NULL;
    this->bGameSettingsChanged = false;
    this->ServerSearchActive = false;
    this->IsOnPressStartScreen = false;
    this->HasSeenStartScreen = false;
    this->ProceduralLevel = NULL;
    this->IconGenerationManagerClass = NULL;
    this->IconGenerationManager = NULL;
    this->CampaignManager = NULL;
    this->RunManager = NULL;
    this->DesiredDifficulty = NULL;
    this->SaveGame = NULL;
    this->ShowCharacterSelectionWorld = false;
    this->Viewer3DClass = NULL;
    this->ShowLoaderWorld = false;
    this->CharacterSelectionWorldActive = false;
    this->MixerInteractivityEnabled = false;
    this->LoaderWorldActive = false;
    this->ResetHUDWhenReturning = false;
    this->MovieModeActive = false;
    this->MovieModeActiveInSpacerig = false;
    this->MovieModeStartAtOrigin = false;
    this->MovieModeStartWithCameraShake = false;
    this->ActiveForgeSchematic = NULL;
    this->FSDCloudLoadSave = NULL;
    this->SendToURL = CreateDefaultSubobject<UFSDSendToURL>(TEXT("FSDSendToURL"));
    this->FriendsAndInvites = NULL;
    this->SessionStartTime = 0.00f;
    this->SessionStartTimestamp = 0;
    this->InKBytesPerSecond = 0.00f;
    this->OutKBytesPerSecond = 0.00f;
    this->PreSpawnNigaraParticles = true;
    this->ControllerVibrationSubmix = NULL;
    this->ControllerSpeakerSubmix = NULL;
    this->ChatHasFocus = false;
    this->TransitionMusicComponent = NULL;
}

void UFSDGameInstance::UpdateGlobelMissionSeed() {
}

void UFSDGameInstance::StopPhotographyInputProcessor() {
}

void UFSDGameInstance::StopPersonalAnalytics() {
}

void UFSDGameInstance::StartPhotographyInputProcessor() {
}

void UFSDGameInstance::StartPersonalAnalytics() {
}

AProceduralSetup* UFSDGameInstance::SpawnProcedural() {
    return NULL;
}

void UFSDGameInstance::ShowEndScreenLevel() {
}

void UFSDGameInstance::SetViewer3DClass(TSubclassOf<AActor> NewClass, ECharselectionCameraLocation Location) {
}

void UFSDGameInstance::SetSteamServerJoinStatus(ESteamServerJoinStatus NewStatus) {
}

void UFSDGameInstance::SetSteamSearchRegion(ESteamSearchRegion NewRegion) {
}

void UFSDGameInstance::SetServerSearchOptions(const FFSDServerSearchOptions& Options) {
}

void UFSDGameInstance::SetServerSearchActive(bool Active) {
}

void UFSDGameInstance::SetProceduralMap(TSubclassOf<AProceduralSetup> procedural) {
}

void UFSDGameInstance::SetMinersManualNotification(EMinersManualSection Section, UObject* IdentifyingObject, FText Text) {
}

void UFSDGameInstance::SetLoaderWorldVisible(bool V, bool ResetHUD) {
}

void UFSDGameInstance::SetHasSeenInfoScreen() {
}

void UFSDGameInstance::SetGlobalMissionSeed(int32 Seed) {
}


void UFSDGameInstance::SetCharacterSelectionWorldVisible(bool V, ECharselectionCameraLocation CameraLocation, bool ResetHUD, ECharacterSelectorItemStatus itemStatus) {
}

void UFSDGameInstance::SetCharacterSelectionSwitcher(ACharacterSelectionSwitcher* switcher) {
}

void UFSDGameInstance::SetBXEDroneInstance(ABXECompanionDrone* NewDrone) {
}

void UFSDGameInstance::SetBoscoInstance(ABosco* NewBosco) {
}

void UFSDGameInstance::SendSteamInfo() {
}

void UFSDGameInstance::ScheduleResetOfWorldsAndGameDataThenOpenLevel(FName LevelName) {
}

void UFSDGameInstance::RestoreCursors() {
}

void UFSDGameInstance::ResetViewer3DClass() {
}

void UFSDGameInstance::ResetSaveGame() {
}

void UFSDGameInstance::ResetAlwaysLoadedWorldsAndGameData() {
}

void UFSDGameInstance::RemoveBXEDrone() {
}

void UFSDGameInstance::RemoveBosco() {
}

void UFSDGameInstance::RemoveAllTemporaryBuff(APlayerController* PlayerController) {
}

void UFSDGameInstance::PreClientTravelCleanup(APlayerController* PlayerController) {
}

void UFSDGameInstance::PostInit(bool reload) {
}

void UFSDGameInstance::PairingUsePreviousProfile() {
}

void UFSDGameInstance::PairingUseNewProfile() {
}


void UFSDGameInstance::OnGameStateSet(const AGameStateBase* GameStateBase) {
}

void UFSDGameInstance::OnGameStateChanged(const FOnGameStateDelegate& OnNewStateSet, bool CallInstantlyIfAlreadySet) {
}

void UFSDGameInstance::LoadSaveGame(UFSDSaveGame* toLoad) {
}

bool UFSDGameInstance::IsMutatorActive(TSubclassOf<UMutator> mutatorClass) const {
    return false;
}

bool UFSDGameInstance::IsGenericMutatorActive(FName InTag) const {
    return false;
}

bool UFSDGameInstance::IsFreeBeerRewardActive() const {
    return false;
}

bool UFSDGameInstance::IsCharacterSelectionWorldVisible() const {
    return false;
}

bool UFSDGameInstance::IsCampaignMission() {
    return false;
}

void UFSDGameInstance::HideEndScreenLevel() {
}

bool UFSDGameInstance::HasSignedIn() {
    return false;
}

bool UFSDGameInstance::HasRandomBeerBuff() const {
    return false;
}

bool UFSDGameInstance::HasPendingActivity() const {
    return false;
}

bool UFSDGameInstance::HasAnalytics() {
    return false;
}

void UFSDGameInstance::GraphicsUserSettingsChanged() {
}

void UFSDGameInstance::GiveTemporaryBuff(UTemporaryBuff* buff, APlayerCharacter* Player) {
}

FVector2D UFSDGameInstance::GetViewportSize() {
    return FVector2D{};
}

TSoftClassPtr<AProceduralSetup> UFSDGameInstance::GetSoftReferenceToPLS() {
    return NULL;
}

EOnlineSessionType UFSDGameInstance::GetSessionType() const {
    return EOnlineSessionType::Solo;
}

TArray<FBlueprintSessionResult> UFSDGameInstance::GetServersFriendsArePlaying(TArray<FBlueprintSessionResult> servers) {
    return TArray<FBlueprintSessionResult>();
}

FString UFSDGameInstance::GetSeedString(UObject* WorldContextObject) {
    return TEXT("");
}

TArray<UMutator*> UFSDGameInstance::GetMutators(TSubclassOf<UMutator> mutatorClass) const {
    return TArray<UMutator*>();
}

AFSDPlayerController* UFSDGameInstance::GetLocalFSDPlayerController() const {
    return NULL;
}

UIconGenerationManager* UFSDGameInstance::GetIconGenerationManager() const {
    return NULL;
}

bool UFSDGameInstance::GetHasSeenInfoScreen() {
    return false;
}

int32 UFSDGameInstance::GetGlobalMissionSeed() const {
    return 0;
}

UMutator* UFSDGameInstance::GetFirstMutator(TSubclassOf<UMutator> mutatorClass) const {
    return NULL;
}

TArray<FNetworkConnectionInfo> UFSDGameInstance::GetConnectionInfo() {
    return TArray<FNetworkConnectionInfo>();
}

APlayerCharacter* UFSDGameInstance::GetCharacterSelectorCharacter() {
    return NULL;
}

UStage* UFSDGameInstance::GetActiveStage() const {
    return NULL;
}

void UFSDGameInstance::GameUserSettingsChanged() {
}

FText UFSDGameInstance::ChatState_UncommitedMessage() {
    return FText::GetEmpty();
}

void UFSDGameInstance::ChatState_StoreState(bool focus, const FText& uncommitedMessage) {
}

bool UFSDGameInstance::ChatState_HadFocus() {
    return false;
}

void UFSDGameInstance::ChangeSkinPreview(UItemSkin* PreviewSkin) {
}

void UFSDGameInstance::CachePSOsOnCommand() {
}

void UFSDGameInstance::BroadcastActiveStageChanged(UStage* NewActiveStage) {
}


UHUDWarningWidget* UFSDGameInstance::AddWarningToHUD(TSubclassOf<UHUDWarningWidget> WidgetClass, UTexture2D* Texture, USoundBase* PingSound) {
    return NULL;
}

void UFSDGameInstance::AddToFriendSessions(const FString& friendSessionId, const FString& friendName) {
}

void UFSDGameInstance::AddStatValue(const FString& Key, float Value) {
}

void UFSDGameInstance::AddStatCount(const FString& Key, int32 count) {
}


