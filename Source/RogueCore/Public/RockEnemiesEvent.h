#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "GameEvent.h"
#include "Templates/SubclassOf.h"
#include "RockEnemiesEvent.generated.h"

class APawn;
class AProjectile;
class UEnemyGroupDescriptor;
class UFXSystemAsset;
class UHealthComponentBase;
class USkeletalMeshComponent;
UCLASS(Blueprintable, NoExport)
class ARockEnemiesEvent : public AGameEvent {
    GENERATED_BODY()
    // UPROPERTY fields moved from protected section

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))

    USkeletalMeshComponent* mesh;

    UFXSystemAsset* MuzzleEffect;

    int32 PowerUpsPerGeneration;

    int32 GruntPointsAward;

    int32 TankPointsAward;

    UEnemyGroupDescriptor* RockEnemies;

    ARockEnemiesEvent(const FObjectInitializer& ObjectInitializer);



public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<AProjectile> PowerUpClass;
    
    float PowerUpGenerationTime;
    TArray<int32> KillAmountPerPlayer;
    TArray<int32> MaxEnemyCountPerPlayer;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TArray<APawn*> SpawnedRockEnemies;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    USkeletalMeshComponent* mesh;
    UFXSystemAsset* MuzzleEffect;
    int32 PowerUpsPerGeneration;
    int32 GruntPointsAward;
    int32 TankPointsAward;
    UEnemyGroupDescriptor* RockEnemies;
    ARockEnemiesEvent(const FObjectInitializer& ObjectInitializer);
    UFUNCTION(BlueprintCallable)
    void StopPowerupGeneration();
    void StartPowerupGeneration();
    void SpawnRockEnemies(float Difficulty, const TArray<FVector>& Locations);
    UFUNCTION(BlueprintCallable, NetMulticast, Unreliable)
    void ShowFireEffects(int32 selectedBone);
    void RockEnemySpawned(APawn* spawnedEnemy);
    void RockEnemyDied(UHealthComponentBase* Health);
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnShoot();
    void EnemySpawnedAfterComplete(APawn* spawnedEnemy);
};
