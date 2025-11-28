#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Curves/CurveFloat.h"
#include "BXEDifficultyPoint.h"
#include "DelegateDelegate.h"
#include "WaveDifficultyController.h"
#include "DifficultyController.generated.h"

class UDifficultyManager;
class UStageDifficultyProgression;
UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class UDifficultyController : public UActorComponent {
    GENERATED_BODY()
    
    
public:
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FDelegate WavePredictionCalculated;
    
 
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, ReplicatedUsing=OnRep_CachedFutureWaves, meta=(AllowPrivateAccess=true))
    TArray<FBXEDifficultyPoint> CachedFutureWaves;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, Transient, meta=(AllowPrivateAccess=true))
    UDifficultyManager* DifficultyManager;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FWaveDifficultyController NormalWaveController;
    UStageDifficultyProgression* StageDifficultyProgression;
    float SoonNewDifficultyTime;
    bool EnemyCountModifierUsed;
    FRuntimeFloatCurve EnemyCountModifierScaleOverTime;
    int32 CurrentDifficulty;
    float NextDifficultyTime;
    float SoonNextDifficultyTime;
    float WarningTimeBeforeNextDifficulty;
    UDifficultyController(const FObjectInitializer& ObjectInitializer);
    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
    UFUNCTION(BlueprintCallable)
    void TriggerNewDifficulty_Server(const FBXEDifficultyPoint& Difficulty);
    UFUNCTION(BlueprintCallable, Reliable, Server)
    void Server_IncrementDifficulty();
    void ResetForNewLevel();
    UFUNCTION()
    void OnRep_CachedFutureWaves();
    UFUNCTION(BlueprintCallable, BlueprintPure)
    float GetTimeToNextDifficulty() const;
    UStageDifficultyProgression* GetStageDifficultyProgression() const;
    FBXEDifficultyPoint GetFutureWave(int32 Index) const;
    TArray<FBXEDifficultyPoint> GetAllFutureWaves() const;
    void CacheWavePredictions(float TimeToNextWave);
};
