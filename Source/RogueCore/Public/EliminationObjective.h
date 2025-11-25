#pragma once
#include "CoreMinimal.h"
#include "EliminationDescriptors.h"
#include "EliminationTarget.h"
#include "Objective.h"
#include "EliminationObjective.generated.h"

class AActor;
class AFSDPawn;
class UCaveInfluencer;
class UDebrisBase;
class UDebrisPositioning;
class UEnemyDescriptor;
class UHealthComponentBase;
UCLASS(Abstract, Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class ROGUECORE_API UEliminationObjective : public UObjective {
    GENERATED_BODY()
    // UPROPERTY fields moved from protected section

public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 ObjectCount;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UDebrisPositioning* Positioning;
    TArray<int32> ExcludeRoomIDs;
    TSoftClassPtr<AActor> ObjectToSpawn;
    UCaveInfluencer* CaveInfluencer;
    float DebrisRadius;
    TArray<TSoftObjectPtr<UDebrisBase>> ObjectDebris;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, ReplicatedUsing=OnRep_EnemiesKilled, meta=(AllowPrivateAccess=true))
    int32 EnemiesKilled;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, ReplicatedUsing=OnRep_EnemiesToKill, meta=(AllowPrivateAccess=true))
    int32 EnemiesToKill;
    TArray<FEliminationDescriptors> TargetDescriptors;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TArray<FEliminationDescriptors> TargetQueue;
    TArray<FEliminationTarget> ActiveEliminationTargets;
    UEliminationObjective(const FObjectInitializer& ObjectInitializer);
    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
    UFUNCTION(BlueprintAuthorityOnly, BlueprintCallable)
    void RegisterEliminationTargets(const TArray<AFSDPawn*>& Targets);
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void ReceiveTargetSpawned();
    void ReceiveTargetKilled();
    UFUNCTION(BlueprintCallable)
    void OnTargetKilled(UHealthComponentBase* Health);
    UFUNCTION()
    void OnRep_EnemiesToKill(int32 prevAmount);
    UFUNCTION()
    void OnRep_EnemiesKilled(int32 prevAmount);
    TArray<UEnemyDescriptor*> GetNextTargetInQueue();
};
