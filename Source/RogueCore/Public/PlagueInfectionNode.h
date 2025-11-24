#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "DelegateDelegate.h"
#include "FirstPlayerNearCenterDelegate.h"
#include "PlagueCenterKilledDelegate.h"
#include "Templates/SubclassOf.h"
#include "PlagueInfectionNode.generated.h"

class UCurveFloat;
class UDebrisPositioning;
class UHealthComponentBase;
class USimpleHealthComponent;
class UTerrainMaterial;
UCLASS(Abstract, Blueprintable, NoExport)
class APlagueInfectionNode : public AActor {
    GENERATED_BODY()
    // UPROPERTY fields moved from protected section

public:
    UPROPERTY(BlueprintAssignable, BlueprintCallable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FFirstPlayerNearCenter OnFirstPlayerNearCenter;
    
    FPlagueCenterKilled OnPlagueCenterKilled;
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    USimpleHealthComponent* HealthComponent;
    FDelegate TriggerCleanupTutorial;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UTerrainMaterial* PlagueTerrainMaterial;
    float NodeInfluenceRadius;
    int32 NumberOfDeathEffectParticles;
    float HealthPercentageToKill;
    TSubclassOf<AActor> WormPodClass;
    float ImportantLocationRadius;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TArray<AActor*> ActiveWorms;
    TArray<AActor*> ActivePods;
    int32 MaxWormCount;
    float WormPodInterval;
    int32 MinWormPodWave;
    int32 MaxWormPodWave;
    UDebrisPositioning* WormPodPositioning;
    UCurveFloat* AvoidCost;
    float WormSpawnTimeDeviation;
    float PassiveWormSpawnTime;
    float ActiveWormSpawnTime;
    float WormSpawnRange;
    float ActivationRange;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Replicated, meta=(AllowPrivateAccess=true))
    bool HasCleanPodBeenSpawned;
    APlagueInfectionNode(const FObjectInitializer& ObjectInitializer);
    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
    UFUNCTION(BlueprintCallable)
    void OnWormSpawned(AActor* worm);
    void OnWormDestroyed(AActor* DestroyedActor);
    void OnPodDestroyed(AActor* DestroyedActor);
    void OnDeath(UHealthComponentBase* Health);
    void CountNodePlague();
};
