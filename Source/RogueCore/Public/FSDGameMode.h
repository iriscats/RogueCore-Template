#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "GameFramework/GameMode.h"
#include "AllReadySignatureDelegate.h"
#include "CallDonkeyDelegate.h"
#include "ECriticalItemPass.h"
#include "EPauseReason.h"
#include "MatchStartedSignatureDelegate.h"
#include "NamedCountdownFloat.h"
#include "PlayerLoggedInDelegate.h"
#include "Templates/SubclassOf.h"
#include "FSDGameMode.generated.h"

class AActor;
class ABosco;
class AFSDGameMode;
class AFSDPlayerController;
class AMolly;
class APlayerCharacter;
class APlayerController;
class ATeamTransport;
class UCritterManager;
class UDifficultyController;
class UDifficultyManager;
class UEncounterManager;
class UEnemyDescriptor;
class UEnemySpawnManager;
class UEnemyWaveManager;
class UFormationsManagerComponent;
class UKeepInsideWorld;
class UObjectivesManager;
class UPheromoneSpawnerComponent;
class UStageManager;
class UStaticSpawnPointManager;
class UWidget;
UCLASS(Blueprintable, NoExport, NonTransient)
class ROGUECORE_API AFSDGameMode : public AGameMode {
    GENERATED_BODY()
    // UPROPERTY fields moved from protected section

public:
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FMatchStartedSignature OnMatchStarted;
    
    FAllReadySignature OnAllControllersReady;
    FPlayerLoggedIn OnPlayerLoggedIn;
    FCallDonkey OnDonkeyCalled;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    bool GenerationStarted;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UPheromoneSpawnerComponent* PheromoneComponent;
    UEnemySpawnManager* EnemySpawnManager;
    UObjectivesManager* ObjectivesManager;
    UKeepInsideWorld* KeepInsideWorld;
    UStageManager* MissionManager;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, Transient, meta=(AllowPrivateAccess=true))
    UEncounterManager* EncounterManagerComponent;
    UCritterManager* CritterManager;
    TArray<AFSDPlayerController*> PlayerControllers;
    UStaticSpawnPointManager* StaticSpawnPointManager;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSoftClassPtr<ATeamTransport> DropPodClass;

 
    UFormationsManagerComponent* FormationsManager;
    TSoftClassPtr<AMolly> MuleClass;
    TSoftClassPtr<ATeamTransport> DropodEscapeClass;
    TSoftClassPtr<ATeamTransport> DropodEscapeSafeClass;
    TSoftClassPtr<ABosco> DroneClass;
    TSoftClassPtr<UWidget> CheatUI;
    bool PreventAllLatejoin;
    bool PreventLateJoinOnMissionStart;
    float PlayerSpawnHeightOffset;
    float FriendlyFireGracePeriod;
    TArray<UEnemyDescriptor*> ForcedEnemyPool;
    TArray<UEnemyDescriptor*> ForcedStationaryPool;
    bool UseNormalEncounters;
    bool UseStationaryEncounter;
    bool AllowSpecialEncounters;
    UEnemyWaveManager* CachedWaveManager;
    bool MissionWasAborted;
    TArray<FNamedCountdownFloat> NamedCountdowns;
    AFSDGameMode(const FObjectInitializer& ObjectInitializer);
    UFUNCTION(BlueprintCallable)
    void StartGame();
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void SpawnMissionCriticalItems(const ECriticalItemPass& pass);
    void SignalLevelEndToAll();
    void SetForcedStationaryPool(const TArray<UEnemyDescriptor*>& pool);
    void SetForcedEnemyPool(const TArray<UEnemyDescriptor*>& pool);
    void RecieveEndLevel();
    void RecieveAllDwarvesDown();
    void Recieve_GotoNextLevel();
    void ReceivePostSeamlessTravel();
    void ReceiveBeginEndLevelAsSuccess();
    void OnObjectivesInitialized();
    void OnLevelGenerationComplete(int32 pass);
    void OnControllerDestroyed(AActor* Controller);
    void LoadSpaceRig();
    void LoadMission(const FString& MapName, TSoftClassPtr<AFSDGameMode> optionalGameMode, bool ClearPlayerState);
    void HostAbortMission();
    void HandlePlayerBanning(AFSDPlayerController* FSDPlayerController);
    void GotoNextLevel();
    UFUNCTION(BlueprintCallable, BlueprintPure)
    UEnemyWaveManager* GetWaveManager() const;
    AActor* GetPlayerStart(AFSDPlayerController* Controller);
    UFUNCTION(BlueprintCallable, BlueprintPure=false)
    TArray<AFSDPlayerController*> GetPlayerControllers() const;
    TSubclassOf<AMolly> GetMuleClass() const;
    UEncounterManager* GetEncounterManager() const;
    FSoftObjectPath GetDropPodPath() const;
    FSoftObjectPath GetDropPodEscapeSafePath() const;
    TSubclassOf<ATeamTransport> GetDropPodEscapeSafeClass() const;
    FSoftObjectPath GetDropPodEscapePath() const;
    TSubclassOf<ATeamTransport> GetDropPodEscapeClass() const;
    TSubclassOf<ATeamTransport> GetDropPodClass() const;
    FSoftObjectPath GetDronePath() const;
    TSubclassOf<ABosco> GetDroneClass() const;
    UDifficultyManager* GetDifficultyManager() const;
    UDifficultyController* GetDifficultyController() const;
    int32 GetCurrentLevel() const;
    bool FSDSetPause(APlayerController* PC, EPauseReason pauseReason);
    bool FSDKickPlayer(APlayerController* KickedPlayer, const FText& KickReason);
    bool FSDClearPause(EPauseReason pauseReason);
    void EndLevelAsSuccess();
    void EndLevel();
    void DonkeyButtonPressed();
    void DestroyNonLocalPlayers();
    UFUNCTION(BlueprintCallable, Exec)
    void Debug_ShowPlayerSpheres();
    void CleanupActorsOfTypes(TArray<TSubclassOf<AActor>> Types, TArray<TSubclassOf<AActor>> dontRemoveTypes);
    UFUNCTION(BlueprintAuthorityOnly, BlueprintCallable, BlueprintPure)
    bool AllPlayersHaveSelectedCharacter() const;
    bool AllPlayersHaveGeneratedLevel() const;
    void AddControllerForGracePeriod(APlayerCharacter* aPlayerCharacter);
    void AboutMission();
};
