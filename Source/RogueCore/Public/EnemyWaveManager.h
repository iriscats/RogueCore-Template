#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "DelegateDelegate.h"
#include "NormalWaveSpawnedDelegate.h"
#include "Templates/SubclassOf.h"
#include "WaveEntry.h"
#include "EnemyWaveManager.generated.h"

class ACorespawnRift;
class AFSDGameMode;
class APawn;
class UEnemySpawnManager;
class UEnemyWaveController;
class UObject;
UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class UEnemyWaveManager : public UActorComponent {
    GENERATED_BODY()
    // UPROPERTY fields moved from private section

public:
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FNormalWaveSpawned OnNormalWaveTimeUpdated;
    
    FDelegate OnEndWaveTriggered;
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSoftClassPtr<UEnemyWaveController> AlwaysRunningWave;
    TArray<FWaveEntry> ScriptedWaves;
    TArray<FWaveEntry> EndMissionWaves;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TArray<UEnemyWaveController*> ActiveScriptedWaves;
    TArray<UEnemyWaveController*> ActiveSecretWaves;
    float StartDelay;
    float NoWavesBeforeRedTime;
    float spawnRadiusFromSpawnPoint;
    bool ScriptedWavesEnabled;
    bool NormalWavesEnabled;
    TArray<TSoftClassPtr<UObject>> RiftClasses;
    float RiftSpawnDistance;
    TArray<ACorespawnRift*> SpawnedRifts;
    bool RiftsAreOpen;
    int32 RiftSpawnCount;
    bool RiftsArePermanentAndAlwaysActive;
private:
    AFSDGameMode* GameMode;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, Transient, meta=(AllowPrivateAccess=true))
    UEnemySpawnManager* SpawnManager;
    TArray<UObject*> NormalWavesBlockStack;
    TArray<UObject*> ScriptedWavesBlockStack;
    UEnemyWaveManager(const FObjectInitializer& ObjectInitializer);
    UFUNCTION(BlueprintCallable)
    UEnemyWaveController* TriggerWave(TSubclassOf<UEnemyWaveController> waveClass);
    UEnemyWaveController* TriggerSecretWave(TSubclassOf<UEnemyWaveController> waveClass);
    void TriggerEndWave(bool cancelAllWaves);
    void StopAllSecretWaves();
    UFUNCTION(BlueprintAuthorityOnly, BlueprintCallable)
    void SpawnScriptedWave();
    void SetAllWavesAreBlocked(const bool allWavesAreBlocked);
    void PushDisableScriptedWaves(UObject* Owner);
    void PushDisableNormalWaves(UObject* Owner);
    void PopDisableScriptedWaves(UObject* Owner);
    void PopDisableNormalWaves(UObject* Owner);
    void OnMatchEnded();
    void OnEnemySpawned(APawn* Enemy);
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsScriptedWaveActive() const;
    bool GetAllWavesAreBlocked() const;
    bool AreScriptedWavesBlocked() const;
    bool AreNormalWavesBlocked() const;
    void AddExternallySpawnedRift(ACorespawnRift* InNewRift);
};
