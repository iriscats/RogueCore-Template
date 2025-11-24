#include "RunManager.h"
#include "BXEAmmoUnlockManager.h"
#include "BXEDamageUnlockManager.h"
#include "BXELogicUnlockManager.h"
#include "BXENegotiationManager.h"
#include "FSDEventsHandler.h"
#include "ReadyUpManager.h"
#include "VoteManager.h"

URunManager::URunManager() {
    this->NegotiationManager = CreateDefaultSubobject<UBXENegotiationManager>(TEXT("NegotiationManager"));
    this->ReadyUpManager = CreateDefaultSubobject<UReadyUpManager>(TEXT("ReadyUpManager"));
    this->VoteManager = CreateDefaultSubobject<UVoteManager>(TEXT("VoteManager"));
    this->RunHistoryManager = NULL;
    this->LogicUnlockManager = CreateDefaultSubobject<UBXELogicUnlockManager>(TEXT("LogicUnlockManager"));
    this->DamageUnlockManager = CreateDefaultSubobject<UBXEDamageUnlockManager>(TEXT("DamageUnlockManager"));
    this->AmmoUnlockManager = CreateDefaultSubobject<UBXEAmmoUnlockManager>(TEXT("AmmoUnlockManager"));
    this->EventsHandler = CreateDefaultSubobject<UFSDEventsHandler>(TEXT("EventsHandler"));
    this->GameStateComponent = NULL;
    this->ActiveRun = NULL;
    this->CurrentCaveDepth = 0.00f;
    this->ObjectiveRewardRegistered = 0;
}

void URunManager::StartRun(const FRunCreationParameters& Parameters) {
}

void URunManager::SetRiskVectorsInBugReporter() {
}

void URunManager::RemoveLevelUpBlocker(AActor* blocker) {
}

void URunManager::PotentExpeniteDispensed() {
}

void URunManager::PotentExpeniteCollected() {
}

void URunManager::OnObjectivesChanged() {
}

bool URunManager::MoveToNextStage() {
    return false;
}

void URunManager::MissionShout(UObject* WorldContext, EMissionShoutID InShoutID) const {
}

void URunManager::MarkActiveStageComplete() {
}

bool URunManager::IsStageComplete(int32 BranchIndex) const {
    return false;
}

bool URunManager::IsSecondToLastStageActive() const {
    return false;
}

bool URunManager::IsLevelUpBlocked() {
    return false;
}

bool URunManager::IsLastStageActive() const {
    return false;
}

bool URunManager::IsFirstStageActive() const {
    return false;
}

bool URunManager::IsActiveStageCompleted() const {
    return false;
}

bool URunManager::IsActive() const {
    return false;
}

void URunManager::IncrementTotalArtifactGiversSpawned() {
}

bool URunManager::HaveActiveStage() const {
    return false;
}

bool URunManager::HaveActiveRun() const {
    return false;
}

bool URunManager::HasUnclaimedRewards() const {
    return false;
}

bool URunManager::HasPendingPotentExpeniteUpgrade() const {
    return false;
}

bool URunManager::HasPendingArtifactUpgrade() const {
    return false;
}

int32 URunManager::GetXPToChipConversionRate() const {
    return 0;
}

float URunManager::GetWaveIntervalMultiplier() const {
    return 0.0f;
}

UVoteManager* URunManager::GetVoteManager() const {
    return NULL;
}

int32 URunManager::GetUnclaimedRewards() const {
    return 0;
}

void URunManager::GetTotalObjectivesCompleted(int32& OutCount) const {
}

int32 URunManager::GetTotalArtifactGiversSpawned() const {
    return 0;
}

FString URunManager::GetStageSeedString() const {
    return TEXT("");
}

FText URunManager::GetStageName(int32 BranchIndex) const {
    return FText::GetEmpty();
}

UStage* URunManager::GetStageAtIndex(const int32 StageIndex) const {
    return NULL;
}

int32 URunManager::GetRunXp() const {
    return 0;
}

int32 URunManager::GetRunSeed() const {
    return 0;
}

URunHistoryManager* URunManager::GetRunHistoryManager() const {
    return NULL;
}

int32 URunManager::GetRewardsAwarded() const {
    return 0;
}

UReadyUpManager* URunManager::GetReadyUpManager() const {
    return NULL;
}

int32 URunManager::GetRandomEquipmentSeed() const {
    return 0;
}

int32 URunManager::GetPotentExpeniteDispensed() const {
    return 0;
}

int32 URunManager::GetPotentExpeniteCollected() const {
    return 0;
}

void URunManager::GetPerObjectiveXP(int32& perObjective) const {
}

void URunManager::GetPerKillXP(int32& perKill) const {
}

void URunManager::GetPerExpeniteXP(int32& perExpenite) const {
}

int32 URunManager::GetNumberOfStages() const {
    return 0;
}

int32 URunManager::GetNumberOfCompletedStages() const {
    return 0;
}

int32 URunManager::GetNumberOfClaimableChips() const {
    return 0;
}

int32 URunManager::GetNumberOfChips() const {
    return 0;
}

float URunManager::GetNextLevelXP() const {
    return 0.0f;
}

UBXENegotiationManager* URunManager::GetNegotiationManager() const {
    return NULL;
}

TSoftClassPtr<ADebrisDataActor> URunManager::GetModeExtraDebris() const {
    return NULL;
}

int32 URunManager::GetLevel() const {
    return 0;
}

void URunManager::GetExpeniteCollected(int32& outCollected) const {
}

float URunManager::GetEnemyResistanceModifier(EEnemyHealthScaling healthScaling) const {
    return 0.0f;
}

float URunManager::GetEnemyDamageModifier() const {
    return 0.0f;
}

float URunManager::GetCurrentXP() const {
    return 0.0f;
}

float URunManager::GetCurrentPotentialXP() const {
    return 0.0f;
}

float URunManager::GetCurrentPotentialLevelProgress() const {
    return 0.0f;
}

float URunManager::GetCurrentLevelProgress() const {
    return 0.0f;
}

UBiome* URunManager::GetBiomeFromStageID(int32 StageID) const {
    return NULL;
}

int32 URunManager::GetArtifactsDispensed() const {
    return 0;
}

int32 URunManager::GetArtifactsCollected() const {
    return 0;
}

UStageTemplateDifficulty* URunManager::GetActiveStageDifficulty() const {
    return NULL;
}

UStage* URunManager::GetActiveStage() const {
    return NULL;
}

URunTemplate* URunManager::GetActiveRunTemplate() const {
    return NULL;
}

FText URunManager::GetActiveRunName() const {
    return FText::GetEmpty();
}

URun* URunManager::GetActiveRun() const {
    return NULL;
}

UBiome* URunManager::GetActiveBiome() const {
    return NULL;
}

void URunManager::GetAccumulatedObjectiveXP(int32& perPrimary) const {
}

void URunManager::ClearRun() {
}

int32 URunManager::ClaimAllClaimableChips() {
    return 0;
}

void URunManager::CheatPrintStages() {
}

bool URunManager::Cheat_DroneApplyUnlock(UBXEUnlockBase* InUnlock) {
    return false;
}

void URunManager::BeginNegotiation(UUnlockCollectionTag* InCollectionTag, int32 Seed) {
}

void URunManager::ArtifactDispensed() {
}

void URunManager::ArtifactCollected() {
}

void URunManager::AddReward() {
}

void URunManager::AddLevelUpBlocker(AActor* blocker) {
}

int32 URunManager::AddChips(int32 InAmount) {
    return 0;
}

void URunManager::AddAdditionalRiskVector(URiskVector* RiskVector) {
}


