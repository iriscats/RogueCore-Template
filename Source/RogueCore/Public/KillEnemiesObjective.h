#pragma once
#include "CoreMinimal.h"
#include "Objective.h"
#include "KillEnemiesObjective.generated.h"

class APawn;
class UDebrisPositioning;
class UEnemyDescriptor;
class UHealthComponentBase;
UCLASS(Abstract, Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class UKillEnemiesObjective : public UObjective {
    GENERATED_BODY()
    // UPROPERTY fields moved from protected section

public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 EnemyCount;
    
    int32 ExtraEnemies;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UDebrisPositioning* Positioning;
    UEnemyDescriptor* EnemyTarget;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, ReplicatedUsing=OnRep_EnemiesKilled, meta=(AllowPrivateAccess=true))
    int32 EnemiesKilled;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, ReplicatedUsing=OnRep_EnemiesToKill, meta=(AllowPrivateAccess=true))
    int32 EnemiesToKill;
    UKillEnemiesObjective(const FObjectInitializer& ObjectInitializer);
    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
    UFUNCTION(BlueprintAuthorityOnly, BlueprintCallable, BlueprintPure=false)
    void RegisterTargetSpawned(APawn* Target) const;
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void ReceiveTargetKilled(UHealthComponentBase* Health);
    UFUNCTION(BlueprintCallable)
    void OnTargetKilled(UHealthComponentBase* Health);
    UFUNCTION()
    void OnRep_EnemiesToKill(int32 prevAmount);
    UFUNCTION()
    void OnRep_EnemiesKilled(int32 prevAmount);
};
