#pragma once
#include "CoreMinimal.h"
#include "BossFightInterface.h"
#include "CoreSpawnEnemyBase.h"
#include "DelegateDelegate.h"
#include "ESpawnLordState.h"
#include "SpawnLordStateDelegateDelegate.h"
#include "SpawnLordEnemy.generated.h"

class APawn;
class ASpawnLordAdEnemy;
class UDestructibleSubHealthComponent;
class UEnemyDescriptor;
UCLASS(Blueprintable, NoExport)
class ROGUECORE_API ASpawnLordEnemy : public ACoreSpawnEnemyBase, public IBossFightInterface {
    GENERATED_BODY()
    // UPROPERTY fields moved from protected section

    UPROPERTY(BlueprintReadWrite, EditAnywhere, ReplicatedUsing=OnRep_HasBossfightStarted, meta=(AllowPrivateAccess=true))

    bool HasBossfightStarted;

    ASpawnLordEnemy(const FObjectInitializer& ObjectInitializer);



public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UDestructibleSubHealthComponent* DestructibleSubHealthHead;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UEnemyDescriptor* AdED;
    TArray<ASpawnLordAdEnemy*> Ads;
    float HealingStateTime;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, ReplicatedUsing=OnRep_SpawnLordState, meta=(AllowPrivateAccess=true))
    ESpawnLordState SpawnLordState;
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSpawnLordStateDelegate OnSpawnLordStateChanged;
    FDelegate OnAdsSpawned;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, ReplicatedUsing=OnRep_HasBossfightStarted, meta=(AllowPrivateAccess=true))
    bool HasBossfightStarted;
    ASpawnLordEnemy(const FObjectInitializer& ObjectInitializer);
    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
    UFUNCTION(BlueprintCallable)
    void OnSubHealthDestroyed(UDestructibleSubHealthComponent* subHealth);
    void OnSeePawn(APawn* aPawn);
    UFUNCTION()
    void OnRep_SpawnLordState();
    UFUNCTION()
    void OnRep_HasBossfightStarted();
private:
    void OnInitialGenerationDone();
    void DamageStateTimer(float damageInSeconds);
    // Fix for true pure virtual functions not being implemented
};
