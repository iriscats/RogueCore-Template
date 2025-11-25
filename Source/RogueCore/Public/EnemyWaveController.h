#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "UObject/NoExportTypes.h"
#include "EWaveControllerType.h"
#include "RiftSpawnOverrides.h"
#include "EnemyWaveController.generated.h"

class ACorespawnRift;
UCLASS(Blueprintable)
class UEnemyWaveController : public UObject {
    GENERATED_BODY()

public:
    UEnemyWaveController();

    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void StartWave();

 
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EWaveControllerType Type;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    bool IsComplete;

    bool IsSuitableForSolo;

    UFUNCTION(BlueprintCallable)
    TArray<FVector> SpawnRifts(const FVector InQueryLocation, const FRiftSpawnOverrides Overrides);

    void ResumeWave();

    void RemoveRifts();

    void PauseWave();

    void OnWaveCompleted();

    UFUNCTION(BlueprintCallable, BlueprintPure)
    EWaveControllerType GetType() const;

    void GetNearestRifts(TArray<ACorespawnRift*>& OutRifts, FVector InLocation, int32 InNumberOfRifts) const;

    void GetNearestRiftLocations(TArray<FVector>& OutRifts, FVector InLocation, int32 InNumberOfRifts) const;
};
