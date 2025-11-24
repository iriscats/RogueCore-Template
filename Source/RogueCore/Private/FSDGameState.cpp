#include "FSDGameState.h"
#include "AttackerManagerComponent.h"
#include "BXEGameStateComponent.h"
#include "DifficultyController.h"
#include "DifficultyManager.h"
#include "GemProximityTracker.h"
#include "Net/UnrealNetwork.h"
#include "PlayerProximityTracker.h"
#include "SeasonReplicatorComponent.h"
#include "ShowroomManager.h"
#include "SoundMixManagerComponent.h"
#include "SpawnEffectsComponent.h"
#include "TeamResourcesComponent.h"

AFSDGameState::AFSDGameState(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->EscapePod = NULL;
    this->bTeamDown = false;
    this->CSGWorld = NULL;
    this->LastSupplyPodTimeStamp = 0;
    this->LastCleaningPodTimeStamp = -9999;
    this->ProceduralSetup = NULL;
    this->DelayLateJoin = false;
    this->FakeMovementBase = NULL;
    this->ResourceAmountPenalty = 0.25f;
    this->LossXPPenalty = 1.00f;
    this->LastLeveLifeTime = -1.00f;
    this->LevelTimeDilation = 1.00f;
    this->BoscoReviveCounter = -1;
    this->SpawnEffects = CreateDefaultSubobject<USpawnEffectsComponent>(TEXT("SpawnEffects"));
    this->MeshScaler = NULL;
    this->GemProximityTracker = CreateDefaultSubobject<UGemProximityTracker>(TEXT("GemProximityTracker"));
    this->AttackerManager = CreateDefaultSubobject<UAttackerManagerComponent>(TEXT("AttackerManager"));
    this->DifficultyManagerComponent = CreateDefaultSubobject<UDifficultyManager>(TEXT("DifficultyManager"));
    this->DifficultyControllerComponent = CreateDefaultSubobject<UDifficultyController>(TEXT("DifficultyController"));
    this->SoundMixManager = CreateDefaultSubobject<USoundMixManagerComponent>(TEXT("SoundMixManager"));
    this->SeasonReplicatorComponent = CreateDefaultSubobject<USeasonReplicatorComponent>(TEXT("SeasonReplicator"));
    this->BXEStateComponent = CreateDefaultSubobject<UBXEGameStateComponent>(TEXT("BXEStateComponent"));
    this->TeamResources = CreateDefaultSubobject<UTeamResourcesComponent>(TEXT("TeamResources"));
    this->IsOnSpaceRig = false;
    this->IsInMidstation = false;
    this->PlayerMadeItToDropPod = true;
    this->CurrentDifficultySetting = NULL;
    this->NextWaveLevelTime = 0.00f;
    this->HostilePressure = 0.00f;
    this->IsWaveActive = false;
    this->RememberDifficulty = true;
    this->ProximityTracker = CreateDefaultSubobject<UPlayerProximityTracker>(TEXT("ProximityTracker"));
    this->ShowroomManager = CreateDefaultSubobject<UShowroomManager>(TEXT("ShowroomManager"));
    this->GameStats = NULL;
    this->MissionTime = 0;
    this->MissionStartTime = 0;
    this->PreventLatejoinCharacterDuplication = true;
    this->CountdownRemaining = -1;
    this->CanCarryOverResources = true;
    this->CurrentPlayerSessionLeader = NULL;
}

void AFSDGameState::WaitForInitialGenerationDone(AFSDGameState* GameState, FLatentActionInfo LatentInfo) {
}

void AFSDGameState::UnblockAbilityUsage(AActor* blocker) {
}

void AFSDGameState::StartCountdown(int32 Duration, const FText& countdownName) {
}

void AFSDGameState::SetPreventLatejoinCharacterDuplication(bool prevent) {
}

void AFSDGameState::SetPlayersHaveReachedDroppod(bool newHasPlayerReached) {
}

void AFSDGameState::SetLevelTimeDilation_Implementation(float newTimeDilation) {
}

void AFSDGameState::SetCurrentDifficulty(UDifficultySetting* Setting, bool updateSessionSettings) {
}

void AFSDGameState::ReplicateLeveLifeTime(AFSDPlayerState* InPlayerState) {
}

void AFSDGameState::RemoveRoundEndBlocker(UObject* blocker) {
}

void AFSDGameState::PostLocalizedGameMessage(const FText& Msg, const TArray<FText>& Arguments) {
}

void AFSDGameState::PostGameMessage(const FString& Msg) {
}

void AFSDGameState::OnRepNamedCountdowns(const TArray<FNamedCountdownInt>& PreviousCountdowns) {
}

void AFSDGameState::OnRepEndLevelState() {
}

void AFSDGameState::OnRep_NextWaveLevelTime() {
}

void AFSDGameState::OnRep_MissionTime() {
}

void AFSDGameState::OnRep_LevelTimeDilation() {
}

void AFSDGameState::OnRep_LastLeveLifeTime() {
}

void AFSDGameState::OnRep_IsWaveActive() {
}

void AFSDGameState::OnRep_IsAbilityUsageBlocked(TArray<AActor*> oldBlockers) {
}

void AFSDGameState::OnRep_HostilePressure() {
}

void AFSDGameState::OnRep_FSDSessionID() {
}

void AFSDGameState::OnRep_CurrentDifficultySetting() {
}

void AFSDGameState::OnRep_CountdownText() {
}

void AFSDGameState::OnRep_CountdownRemaining(int32 prevTime) {
}

void AFSDGameState::OnRep_BoscoReviveCounter() {
}

void AFSDGameState::OnRep_ActiveWaveTypes() {
}

void AFSDGameState::OnRep_ActivePlayerCharacters() {
}

void AFSDGameState::OnAbilityBlockerFreed(AActor* DestroyedActor) {
}

bool AFSDGameState::IsTutorialMission() const {
    return false;
}

bool AFSDGameState::IsRoundEndBlocked() const {
    return false;
}

bool AFSDGameState::IsCountingDown() const {
    return false;
}

bool AFSDGameState::IsAbilityUsageBlocked() const {
    return false;
}

void AFSDGameState::InitObjectives() {
}

void AFSDGameState::HostDisbandedTeam_Implementation() {
}

bool AFSDGameState::HaveStageSuccess() const {
    return false;
}

bool AFSDGameState::HaveStageFailure() const {
    return false;
}

bool AFSDGameState::HaveRunSuccess() const {
    return false;
}

bool AFSDGameState::HaveRunFailure() const {
    return false;
}

bool AFSDGameState::HaveRunAbort() const {
    return false;
}

bool AFSDGameState::HaveReplicatedEndOfRunState() const {
    return false;
}

int32 AFSDGameState::HaveActiveWave() const {
    return 0;
}

bool AFSDGameState::HasObjectivesReplicated() const {
    return false;
}


AFSDPlayerState* AFSDGameState::GetServerPlayerState() {
    return NULL;
}

TArray<UObjective*> AFSDGameState::GetSecondaryObjectives() const {
    return TArray<UObjective*>();
}

AProceduralSetup* AFSDGameState::GetProceduralSetup() {
    return NULL;
}

UObjective* AFSDGameState::GetPrimaryObjective() const {
    return NULL;
}

bool AFSDGameState::GetPreventLatejoinCharacterDuplication() const {
    return false;
}

bool AFSDGameState::GetPlayersHaveReachedDroppod() const {
    return false;
}


TArray<UObjective*> AFSDGameState::GetObjectives() const {
    return TArray<UObjective*>();
}

float AFSDGameState::GetNextWaveLevelTime() const {
    return 0.0f;
}

TArray<AFSDPlayerState*> AFSDGameState::GetNetworkSortedPlayerArray() {
    return TArray<AFSDPlayerState*>();
}

int32 AFSDGameState::GetMissionTime() const {
    return 0;
}

int32 AFSDGameState::GetMissionStartTime() const {
    return 0;
}

float AFSDGameState::GetLevelTimeDilation() const {
    return 0.0f;
}

float AFSDGameState::GetLevelLifeTime() const {
    return 0.0f;
}

float AFSDGameState::GetHostilePressure() const {
    return 0.0f;
}

AGameStats* AFSDGameState::GetGameStats() const {
    return NULL;
}

TMap<UResourceData*, float> AFSDGameState::GetEndscreenResources() const {
    return TMap<UResourceData*, float>();
}

UDifficultyManager* AFSDGameState::GetDifficultyManager() const {
    return NULL;
}

UDifficultyController* AFSDGameState::GetDifficultyController() const {
    return NULL;
}

TMap<UResourceData*, float> AFSDGameState::GetCollectedResources() const {
    return TMap<UResourceData*, float>();
}

TArray<EWaveControllerType> AFSDGameState::GetActiveWaveTypes() const {
    return TArray<EWaveControllerType>();
}

TArray<UFSDEvent*> AFSDGameState::GetActiveEventsFromMission() const {
    return TArray<UFSDEvent*>();
}

void AFSDGameState::ClientNewMessage_Implementation(const FFSDChatMessage& Msg) {
}

void AFSDGameState::Client_NewLocalizedMessage_Implementation(const FFSDLocalizedChatMessage& Msg) {
}

void AFSDGameState::BroadcastDepositedResource_Implementation(APlayerCharacter* PlayerThatDeposited, UResourceData* DepositedResource, const float DepositedAmount) {
}

void AFSDGameState::BlockAbilityUsage(AActor* blocker) {
}

void AFSDGameState::All_SpawnScaledEffectAt_Implementation(FScaledEffect Effect, FVector_NetQuantize Location) {
}

void AFSDGameState::All_SpawnScaledEffectAndCueAt_Implementation(FScaledEffect Effect, USoundCue* Audio, FVector_NetQuantize Location) {
}

void AFSDGameState::All_ServerQuit_Implementation() {
}

void AFSDGameState::All_InvalidateMovementAbilities_Implementation() {
}

void AFSDGameState::AddRoundEndBlocker(UObject* blocker) {
}

void AFSDGameState::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const {
    Super::GetLifetimeReplicatedProps(OutLifetimeProps);
    
    DOREPLIFETIME(AFSDGameState, EscapePod);
    DOREPLIFETIME(AFSDGameState, FSDSessionID);
    DOREPLIFETIME(AFSDGameState, RoundEndBlockers);
    DOREPLIFETIME(AFSDGameState, AbilityUsageBlockers);
    DOREPLIFETIME(AFSDGameState, LastLeveLifeTime);
    DOREPLIFETIME(AFSDGameState, LevelTimeDilation);
    DOREPLIFETIME(AFSDGameState, BoscoReviveCounter);
    DOREPLIFETIME(AFSDGameState, ActivePlayerCharacters);
    DOREPLIFETIME(AFSDGameState, Objectives);
    DOREPLIFETIME(AFSDGameState, CurrentDifficultySetting);
    DOREPLIFETIME(AFSDGameState, NextWaveLevelTime);
    DOREPLIFETIME(AFSDGameState, HostilePressure);
    DOREPLIFETIME(AFSDGameState, ActiveWaveTypes);
    DOREPLIFETIME(AFSDGameState, IsWaveActive);
    DOREPLIFETIME(AFSDGameState, MissionTime);
    DOREPLIFETIME(AFSDGameState, PreventLatejoinCharacterDuplication);
    DOREPLIFETIME(AFSDGameState, CountdownRemaining);
    DOREPLIFETIME(AFSDGameState, CountdownText);
    DOREPLIFETIME(AFSDGameState, LevelEndState);
    DOREPLIFETIME(AFSDGameState, NamedCountdowns);
}


