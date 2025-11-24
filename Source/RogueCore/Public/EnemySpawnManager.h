#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Components/ActorComponent.h"
#include "GameplayTagContainer.h"
#include "EnemyDestroyedSignatureDelegate.h"
#include "EnemySpawnedDelegateDelegate.h"
#include "EnemySpawnedSignatureDelegate.h"
#include "SpawnQueueItem.h"
#include "SpawnRarityModifierItem.h"
#include "Templates/SubclassOf.h"
#include "EnemySpawnManager.generated.h"

class AActor;
class APawn;
class AProceduralSetup;
class UEnemyDescriptor;
class UHealthComponentBase;
class USpawnEffectsComponent;
class UStatusEffect;
UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class ROGUECORE_API UEnemySpawnManager : public UActorComponent {
    GENERATED_BODY()
    // UPROPERTY fields moved from private section

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))

    int32 MaxActiveEnemies;

    int32 MaxActiveSwarmers;

    int32 MaxActiveCritters;

    float MaxDistanceBeforeCleanup;

    FGameplayTag SwarmerTag;

    FGameplayTag RegularTag;

    FGameplayTag CritterTag;

    AProceduralSetup* ProceduralSetup;



public:
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FEnemyDestroyedSignature OnEnemyDestroyed;
    
    FEnemyDestroyedSignature OnEnemyDied;
    FEnemySpawnedSignature OnEnemySpawned;
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, Transient, meta=(AllowPrivateAccess=true))
    USpawnEffectsComponent* SpawnEffects;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TArray<APawn*> ActiveEnemies;
    TArray<APawn*> ActiveSwarmerEnemies;
    TArray<TSubclassOf<UStatusEffect>> ActiveGlobalStatusEffects;
    TMap<UEnemyDescriptor*, FSpawnRarityModifierItem> SpawnRarityModifiers;
    TArray<APawn*> ActiveCritters;
    TArray<APawn*> CritcalEnemies;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 MaxActiveEnemies;
    int32 MaxActiveSwarmers;
    int32 MaxActiveCritters;
    float MaxDistanceBeforeCleanup;
    FGameplayTag SwarmerTag;
    FGameplayTag RegularTag;
    FGameplayTag CritterTag;
private:
    AProceduralSetup* ProceduralSetup;
    TArray<FSpawnQueueItem> HotSpawnQueue;
    TArray<FSpawnQueueItem> SpawnQueue;
    bool bDestroyingAllEnemies;
    TSet<UEnemyDescriptor*> AsyncLoadingRequested;
    TMap<AActor*, float> DifficultyOfAlertedAliveEnemiesMap;
    UEnemySpawnManager(const FObjectInitializer& ObjectInitializer);
    UFUNCTION(BlueprintAuthorityOnly, BlueprintCallable)
    void SpawnerDestroyed(APawn* Actor);
    bool SpawnEnemy(UEnemyDescriptor* descriptor, const FTransform& Transform, const FEnemySpawnedDelegate& Callback, bool useSpawnFX, bool Alert);
    UFUNCTION(BlueprintCallable)
    void SetSpawningEnabled(bool newSpawningEnabled);
    void RemoveGlobalStatusEffect(TSubclassOf<UStatusEffect> StatusEffect);
    void RegisterSpawner(APawn* Actor);
    void PromoteToCritical(APawn* Pawn);
    void OnMatchStarted();
    void OnMatchEnded();
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool GetSpawningEnabled() const;
    UFUNCTION(BlueprintAuthorityOnly, BlueprintCallable, BlueprintPure)
    APawn* FindEnemyByClass(TSubclassOf<APawn> PawnClass, bool isSwarmerEnemy) const;
    TArray<APawn*> FindEnemiesByClass(TSubclassOf<APawn> PawnClass, bool isSwarmerEnemy) const;
    void EnemyDestroyed(AActor* Actor);
    void EnemyDeath(UHealthComponentBase* HealthComponent);
    void DestroyAllEnemies();
    bool CanSpawn(UEnemyDescriptor* EnemyDescriptor) const;
    void AddGlobalStatusEffect(TSubclassOf<UStatusEffect> StatusEffect);
};
