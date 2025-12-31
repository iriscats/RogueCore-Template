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
public:
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FNormalWaveSpawned OnNormalWaveTimeUpdated;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FDelegate OnEndWaveTriggered;
    
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSoftClassPtr<UEnemyWaveController> AlwaysRunningWave;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FWaveEntry> ScriptedWaves;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FWaveEntry> EndMissionWaves;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TArray<UEnemyWaveController*> ActiveScriptedWaves;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TArray<UEnemyWaveController*> ActiveSecretWaves;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float StartDelay;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float NoWavesBeforeRedTime;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float spawnRadiusFromSpawnPoint;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    bool ScriptedWavesEnabled;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool NormalWavesEnabled;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<TSoftClassPtr<UObject>> RiftClasses;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float RiftSpawnDistance;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TArray<ACorespawnRift*> SpawnedRifts;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    bool RiftsAreOpen;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 RiftSpawnCount;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool RiftsArePermanentAndAlwaysActive;
    
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    AFSDGameMode* GameMode;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, Transient, meta=(AllowPrivateAccess=true))
    UEnemySpawnManager* SpawnManager;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TArray<UObject*> NormalWavesBlockStack;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TArray<UObject*> ScriptedWavesBlockStack;
    
public:
    UEnemyWaveManager(const FObjectInitializer& ObjectInitializer);

    UFUNCTION(BlueprintCallable)
    UEnemyWaveController* TriggerWave(TSubclassOf<UEnemyWaveController> waveClass);
    
    UFUNCTION(BlueprintCallable)
    UEnemyWaveController* TriggerSecretWave(TSubclassOf<UEnemyWaveController> waveClass);
    
    UFUNCTION(BlueprintCallable)
    void TriggerEndWave(bool cancelAllWaves);
    
    UFUNCTION(BlueprintCallable)
    void StopAllSecretWaves();
    
    UFUNCTION(BlueprintAuthorityOnly, BlueprintCallable)
    void SpawnScriptedWave();
    
    UFUNCTION(BlueprintCallable)
    void SetAllWavesAreBlocked(const bool allWavesAreBlocked);
    
    UFUNCTION(BlueprintAuthorityOnly, BlueprintCallable)
    void PushDisableScriptedWaves(UObject* Owner);
    
    UFUNCTION(BlueprintAuthorityOnly, BlueprintCallable)
    void PushDisableNormalWaves(UObject* Owner);
    
    UFUNCTION(BlueprintAuthorityOnly, BlueprintCallable)
    void PopDisableScriptedWaves(UObject* Owner);
    
    UFUNCTION(BlueprintAuthorityOnly, BlueprintCallable)
    void PopDisableNormalWaves(UObject* Owner);
    
public:
    UFUNCTION(BlueprintCallable)
    void OnMatchEnded();
    
    UFUNCTION(BlueprintCallable)
    void OnEnemySpawned(APawn* Enemy);
    
public:
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsScriptedWaveActive() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool GetAllWavesAreBlocked() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool AreScriptedWavesBlocked() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool AreNormalWavesBlocked() const;
    
    UFUNCTION(BlueprintCallable)
    void AddExternallySpawnedRift(ACorespawnRift* InNewRift);
    
};

