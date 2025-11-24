#include "FSDGameMode.h"
#include "CritterManager.h"
#include "EnemySpawnManager.h"
#include "FormationsManagerComponent.h"
#include "KeepInsideWorld.h"
#include "ObjectivesManager.h"
#include "PheromoneSpawnerComponent.h"
#include "StageManager.h"
#include "StaticSpawnPointManager.h"
#include "Templates/SubclassOf.h"

AFSDGameMode::AFSDGameMode(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->bStartPlayersAsSpectators = true;
    this->bDelayedStart = true;
    this->GenerationStarted = false;
    this->PheromoneComponent = CreateDefaultSubobject<UPheromoneSpawnerComponent>(TEXT("PheromoneManager"));
    this->EnemySpawnManager = CreateDefaultSubobject<UEnemySpawnManager>(TEXT("EnemySpawnManager"));
    this->ObjectivesManager = CreateDefaultSubobject<UObjectivesManager>(TEXT("ObjectivesManager"));
    this->KeepInsideWorld = CreateDefaultSubobject<UKeepInsideWorld>(TEXT("KeepInsideWorld"));
    this->MissionManager = CreateDefaultSubobject<UStageManager>(TEXT("MissionManager"));
    this->EncounterManagerComponent = NULL;
    this->CritterManager = CreateDefaultSubobject<UCritterManager>(TEXT("CritterManager"));
    this->StaticSpawnPointManager = CreateDefaultSubobject<UStaticSpawnPointManager>(TEXT("StaticSpawnPointManager"));
    this->FormationsManager = CreateDefaultSubobject<UFormationsManagerComponent>(TEXT("FormationsManager"));
    this->PreventAllLatejoin = false;
    this->PreventLateJoinOnMissionStart = false;
    this->PlayerSpawnHeightOffset = 75.00f;
    this->FriendlyFireGracePeriod = 240.00f;
    this->UseNormalEncounters = true;
    this->UseStationaryEncounter = true;
    this->AllowSpecialEncounters = true;
    this->CachedWaveManager = NULL;
    this->MissionWasAborted = false;
}

void AFSDGameMode::StartGame() {
}


void AFSDGameMode::SignalLevelEndToAll() {
}

void AFSDGameMode::SetForcedStationaryPool(const TArray<UEnemyDescriptor*>& pool) {
}

void AFSDGameMode::SetForcedEnemyPool(const TArray<UEnemyDescriptor*>& pool) {
}








void AFSDGameMode::OnControllerDestroyed(AActor* Controller) {
}


void AFSDGameMode::LoadMission(const FString& MapName, TSoftClassPtr<AFSDGameMode> optionalGameMode, bool ClearPlayerState) {
}

void AFSDGameMode::HostAbortMission() {
}

void AFSDGameMode::HandlePlayerBanning(AFSDPlayerController* FSDPlayerController) {
}

void AFSDGameMode::GotoNextLevel() {
}

UEnemyWaveManager* AFSDGameMode::GetWaveManager() const {
    return NULL;
}

AActor* AFSDGameMode::GetPlayerStart(AFSDPlayerController* Controller) {
    return NULL;
}

TArray<AFSDPlayerController*> AFSDGameMode::GetPlayerControllers() const {
    return TArray<AFSDPlayerController*>();
}

TSubclassOf<AMolly> AFSDGameMode::GetMuleClass() const {
    return NULL;
}

UEncounterManager* AFSDGameMode::GetEncounterManager() const {
    return NULL;
}

FSoftObjectPath AFSDGameMode::GetDropPodPath() const {
    return FSoftObjectPath{};
}

FSoftObjectPath AFSDGameMode::GetDropPodEscapeSafePath() const {
    return FSoftObjectPath{};
}

TSubclassOf<ATeamTransport> AFSDGameMode::GetDropPodEscapeSafeClass() const {
    return NULL;
}

FSoftObjectPath AFSDGameMode::GetDropPodEscapePath() const {
    return FSoftObjectPath{};
}

TSubclassOf<ATeamTransport> AFSDGameMode::GetDropPodEscapeClass() const {
    return NULL;
}

TSubclassOf<ATeamTransport> AFSDGameMode::GetDropPodClass() const {
    return NULL;
}

FSoftObjectPath AFSDGameMode::GetDronePath() const {
    return FSoftObjectPath{};
}

TSubclassOf<ABosco> AFSDGameMode::GetDroneClass() const {
    return NULL;
}

UDifficultyManager* AFSDGameMode::GetDifficultyManager() const {
    return NULL;
}

UDifficultyController* AFSDGameMode::GetDifficultyController() const {
    return NULL;
}

int32 AFSDGameMode::GetCurrentLevel() const {
    return 0;
}

bool AFSDGameMode::FSDSetPause(APlayerController* PC, EPauseReason pauseReason) {
    return false;
}

bool AFSDGameMode::FSDKickPlayer(APlayerController* KickedPlayer, const FText& KickReason) {
    return false;
}

bool AFSDGameMode::FSDClearPause(EPauseReason pauseReason) {
    return false;
}

void AFSDGameMode::EndLevelAsSuccess() {
}

void AFSDGameMode::EndLevel() {
}


void AFSDGameMode::DestroyNonLocalPlayers() {
}

void AFSDGameMode::Debug_ShowPlayerSpheres() {
}

void AFSDGameMode::CleanupActorsOfTypes(TArray<TSubclassOf<AActor>> Types, TArray<TSubclassOf<AActor>> dontRemoveTypes) {
}

bool AFSDGameMode::AllPlayersHaveSelectedCharacter() const {
    return false;
}

bool AFSDGameMode::AllPlayersHaveGeneratedLevel() const {
    return false;
}

void AFSDGameMode::AddControllerForGracePeriod(APlayerCharacter* aPlayerCharacter) {
}

void AFSDGameMode::AboutMission() {
}


