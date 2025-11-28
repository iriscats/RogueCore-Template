#pragma once
#include "CoreMinimal.h"
#include "Objective.h"
#include "BXEObjectiveLostDronesTreasure.generated.h"

class AActor;
class ABXEObjectivePickupActor;
class ABXEProspectingTreasureRewardSpawner;
class ABXEScannableRewardActor;
class APawn;
class UDebrisPositioning;
class UEnemyDescriptor;
UCLASS(Abstract, Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class ROGUECORE_API UBXEObjectiveLostDronesTreasure : public UObjective {
    GENERATED_BODY()
    
public:

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 EnemyCount;
    
    int32 ExtraEnemies;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UDebrisPositioning* Positioning;
    UEnemyDescriptor* EnemyTarget;
    TSoftClassPtr<ABXEObjectivePickupActor> EnemyDropActor;
    int32 PreferredMinDistanceBetweenSpawns;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, ReplicatedUsing=OnRep_EnemiesKilled, meta=(AllowPrivateAccess=true))
    int32 EnemiesKilled;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, ReplicatedUsing=OnRep_EnemiesToKill, meta=(AllowPrivateAccess=true))
    int32 EnemiesToKill;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Replicated, Transient, meta=(AllowPrivateAccess=true))
    ABXEScannableRewardActor* SpawnedReward;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    ABXEProspectingTreasureRewardSpawner* RewardSpawner;
    TSoftClassPtr<ABXEProspectingTreasureRewardSpawner> RewardSpawnerClass;
    int32 NumToSpawn;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, ReplicatedUsing=OnRep_HasPickedUp, meta=(AllowPrivateAccess=true))
    int32 HasPickedUp;
    UBXEObjectiveLostDronesTreasure(const FObjectInitializer& ObjectInitializer);
    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
    UFUNCTION(BlueprintAuthorityOnly, BlueprintCallable, BlueprintPure=false)
    void RegisterTargetSpawned(APawn* Target) const;
    UFUNCTION(BlueprintCallable)
    void OnTargetKilled(AActor* Actor);
    void OnRewardSpawned();
    UFUNCTION()
    void OnRep_HasPickedUp();
    UFUNCTION()
    void OnRep_EnemiesToKill(int32 prevAmount);
    UFUNCTION()
    void OnRep_EnemiesKilled(int32 prevAmount);
    void AddPickUp();
};
