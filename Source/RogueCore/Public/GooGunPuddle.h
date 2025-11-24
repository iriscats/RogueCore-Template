#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"

#include "DamageData.h"
#include "GooPuddleStatusEffectTrigger.h"
#include "Templates/SubclassOf.h"
#include "GooGunPuddle.generated.h"

class UHealthComponentBase;
class UPrimitiveComponent;
class USimpleHealthComponent;
class USoundBase;
class USphereComponent;
class UStatusEffect;
UCLASS(Blueprintable, NoExport)
class AGooGunPuddle : public AActor {
    GENERATED_BODY()
    // UPROPERTY fields moved from private section

public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    USphereComponent* SphereTrigger;
    
    USimpleHealthComponent* SimpleHealth;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    USoundBase* SpawnSound;
    TArray<FGooPuddleStatusEffectTrigger> StatusEffectTriggers;
    TArray<TSubclassOf<UStatusEffect>> InflictedStatusEffects;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, ReplicatedUsing=OnRep_ActiveStatusEffectTriggersMask, meta=(AllowPrivateAccess=true))
    int32 ActiveStatusEffectTriggersMask;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Replicated, meta=(AllowPrivateAccess=true))
    float Lifetime;
private:
    bool CollisionOnClients;
    AGooGunPuddle(const FObjectInitializer& ObjectInitializer);
    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
    UFUNCTION(BlueprintCallable)
    void SetStatusEffect(TSubclassOf<UStatusEffect> NewStatusEffect);
protected:
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnStatusEffectAdded(const FGooPuddleStatusEffectTrigger& Trigger);
public:
    UFUNCTION()
    void OnRep_ActiveStatusEffectTriggersMask(int32 PreviousMask);
    void OnPuddleEndOverLap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);
    void OnPuddleBeginOverLap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
    void OnHit(float Damage, const FDamageData& DamageData, bool anyHealthLost, UHealthComponentBase* HealthComponent);
    void OnGooIgnited();
    UFUNCTION(BlueprintCallable, NetMulticast, Reliable)
    void IgniteGoo();
    void AddStatusEffect(TSubclassOf<UStatusEffect> NewStatusEffect);
};
