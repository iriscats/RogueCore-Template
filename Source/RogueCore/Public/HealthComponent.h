#pragma once
#include "CoreMinimal.h"
#include "ArmorHealedSigDelegate.h"
#include "DamageData.h"
#include "DamageSigDelegate.h"
#include "DeathSigDetailedDelegate.h"
#include "DelegateDelegate.h"
#include "EHealthbarType.h"
#include "HealthChangedSigDelegate.h"
#include "HealthComponentBase.h"
#include "HealthSegmentChangeDelegate.h"
#include "HealthComponent.generated.h"

class AActor;
class UHealthModifier;
class UPawnStat;
class UPawnStatsComponent;
class USubHealthComponent;
UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class UHealthComponent : public UHealthComponentBase {
    GENERATED_BODY()
    // UPROPERTY fields moved from protected section

public:
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FDelegate OnTemporaryHealthChanged;
    
    FDelegate OnGainedTemporaryHealth;
    FDelegate OnLostTemporaryHealth;
    FHealthChangedSig OnArmorChanged;
    FDamageSig OnArmorDamaged;
    FArmorHealedSig OnArmorHealed;
    UPROPERTY(BlueprintAssignable, BlueprintAuthorityOnly, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FDeathSigDetailed OnDeathDetailed;
    FHealthSegmentChange OnNewHealthSegment;
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<UHealthModifier*> DamageModifiers;
    TArray<float> HealthSegmentSizes;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, Transient, meta=(AllowPrivateAccess=true))
    TArray<USubHealthComponent*> SubHealthComponents;
    TMap<UPawnStat*, float> Resistances;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    AActor* LastDamageCauser;
    UPawnStatsComponent* PawnStats;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, ReplicatedUsing=OnRep_Damage, meta=(AllowPrivateAccess=true))
    float Damage;
    float EnvironmentalDamageResistance;
    bool ShouldUseLargestSubhealthDamageTaken;
    bool InvulnerableToNonDefinedResistances;
    bool AffectedByGlobalWeakpointDamageMultiplier;
    bool UseDormancy;
    bool CanDamageThroughSegments;
    UHealthComponent(const FObjectInitializer& ObjectInitializer);
    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
    UFUNCTION(BlueprintCallable)
    float TakePercentDamage(float PercentOfMax, const FDamageData& DamageData);
    UFUNCTION(BlueprintCallable, Reliable, Server)
    void Server_ToggleGodMode();
    UFUNCTION(BlueprintCallable, Reliable, Server)
    void Server_SetGodMode_Implementation(bool Active);
    UFUNCTION(BlueprintAuthorityOnly, BlueprintCallable)
    void Resupply(float percentage);
    UFUNCTION()
    void OnRep_Damage(float oldDamage);
    void HealArmor(float amount);
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool HasArmor() const;
    float GetTempHealthAmount() const;
    float GetTargetArmorPct() const;
    float GetTargetArmor() const;
    float GetMaxArmor() const;
    AActor* GetLastDamageCauser() const;
    virtual EHealthbarType GetHealthbarType() const override;
    void GetCurrentHealthSegment(int32& Segment, float& segmentHealth, float& segmentHealthPercent);
    float GetArmorPct() const;
    float GetArmorDR() const;
    float GetArmor() const;
    UFUNCTION(BlueprintCallable, Client, Reliable)
    void Client_ReceivedHit(float amount, const FDamageData& DamageData, bool anyHealthLost);
    void AddTemporaryHealth(float amount);
};
