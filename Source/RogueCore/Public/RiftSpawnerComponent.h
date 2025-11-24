#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Components/ActorComponent.h"
#include "DelegateDelegate.h"
#include "RiftSpawnerDelegateDelegate.h"
#include "Templates/SubclassOf.h"
#include "RiftSpawnerComponent.generated.h"

class AActor;
class ACoreRift;
class UDebrisPositioning;
class UDifficultySetting;
UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class URiftSpawnerComponent : public UActorComponent {
    GENERATED_BODY()
    // UPROPERTY fields moved from protected section

public:
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FRiftSpawnerDelegate OnRiftSpawned;
    
    FDelegate OnFinishedSpawningRifts;
    FDelegate OnAllRiftsOpened;
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, ReplicatedUsing=OnRep_Spawned, meta=(AllowPrivateAccess=true))
    TArray<AActor*> spawned;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<UDifficultySetting*, int32> AmountByDifficulty;
    TSubclassOf<ACoreRift> RiftClass;
    UDebrisPositioning* Positioning;
    float SpawnInterval;
    float SpawnDeviation;
    float InitialSpawnDelay;
    int32 AmountToSpawn;
    bool SpawnOneAtATime;
    bool DisallowSpawning;
    URiftSpawnerComponent(const FObjectInitializer& ObjectInitializer);
    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
    UFUNCTION(BlueprintAuthorityOnly, BlueprintCallable)
    void StopSpawning();
    void StartSpawning();
    UFUNCTION(BlueprintCallable)
    void SpawnRift();
    void ReportRiftOpened(AActor* rift);
    void PreFetchSpawnLocations(const FVector& Origin);
    UFUNCTION()
    void OnRep_Spawned();
    TArray<AActor*> GetRifts();
    bool CollectSpawnLocations(const FVector& Origin);
};
