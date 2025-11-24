#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "GameplayTagContainer.h"
#include "EStatusEffectPopSetting.h"
#include "RandRange.h"
#include "Templates/SubclassOf.h"
#include "StatusEffect.generated.h"

class AActor;
class UDamageClass;
class UPawnAffliction;
class UPawnStat;
class UStatusEffect;
class UStatusEffectExclusiveKey;
class UStatusEffectItem;
UCLASS(Blueprintable, EditInlineNew)
class UStatusEffect : public UObject {
    GENERATED_BODY()
    // UPROPERTY fields moved from protected section

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))

    TArray<UStatusEffectItem*> StatusEffects;

    float MaxResistance;

    UDamageClass* DamageClass;

    UStatusEffectExclusiveKey* ExclusiveKey;

    EStatusEffectPopSetting PopSetting;

    bool TriggerTwiceOnPush;

    FRandRange ApplyEffectsInterval;

    bool CanStack;

    int32 MaxStack;

    bool RemoveAllStacksAfterDuration;

    float Duration;

    bool RestartDurationOnApply;

    bool ApplyDurationAfterPop;

    bool RemoveOnDeath;

    bool RemoveOnTemperatureStateChange;

    bool AllowExternalSread;

    bool RefreshDurationOnApplication;

    bool OnlyOneInstanceUpdates;

    FGameplayTagQuery GameplayTagQuery;

    UStatusEffect();

    UFUNCTION(BlueprintCallable, BlueprintPure)

    static float GetStatusEffectDuration(TSubclassOf<UStatusEffect> StatusEffect);



public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UPawnStat* DurationModifier;
    
protected:
    UPawnAffliction* PawnAffliction;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    TArray<UStatusEffectItem*> StatusEffects;
    float MaxResistance;
    UDamageClass* DamageClass;
    UStatusEffectExclusiveKey* ExclusiveKey;
    EStatusEffectPopSetting PopSetting;
    bool TriggerTwiceOnPush;
    FRandRange ApplyEffectsInterval;
    bool CanStack;
    int32 MaxStack;
    bool RemoveAllStacksAfterDuration;
    float Duration;
    bool RestartDurationOnApply;
    bool ApplyDurationAfterPop;
    bool RemoveOnDeath;
    bool RemoveOnTemperatureStateChange;
    bool AllowExternalSread;
    bool RefreshDurationOnApplication;
    bool OnlyOneInstanceUpdates;
    FGameplayTagQuery GameplayTagQuery;
    UStatusEffect();
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static float GetStatusEffectDuration(TSubclassOf<UStatusEffect> StatusEffect);
    UFUNCTION(BlueprintAuthorityOnly, BlueprintCallable, BlueprintPure=false)
    UStatusEffectItem* GetFirstStatusEffectItem(TSubclassOf<UStatusEffectItem> itemClass, bool assertOnFail) const;
    bool CanTrigger(AActor* Target) const;
};
