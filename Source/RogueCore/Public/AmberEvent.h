#pragma once
#include "CoreMinimal.h"
#include "GameEvent.h"
#include "AmberEvent.generated.h"

class AFSDPawn;
class APawn;
class UAmberEventEnemyPool;
class UDamageComponent;
class UHealthComponentBase;
UCLASS(Blueprintable, NoExport)
class AAmberEvent : public AGameEvent {
    GENERATED_BODY()
    // UPROPERTY fields moved from protected section

public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UDamageComponent* EndExplosionDamage;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<UAmberEventEnemyPool*> EnemyPools;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Replicated, Transient, meta=(AllowPrivateAccess=true))
    TWeakObjectPtr<UAmberEventEnemyPool> CurrentPool;

protected:
    TArray<AFSDPawn*> spawnedEnemies;
    float InitialDelayBeforeSpawn;
    float MaxSpawnRange;
    AAmberEvent(const FObjectInitializer& ObjectInitializer);
    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
    UFUNCTION(BlueprintCallable)
    void OnSpawnedDeath(UHealthComponentBase* spawnedHealthComponent);
    void OnEnemySpawned(APawn* Pawn);
};
