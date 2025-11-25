#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "ActiveStatusEffectBank.h"
#include "StatusEffectData.h"
#include "Templates/SubclassOf.h"
#include "StatusEffectsComponent.generated.h"

class AActor;
class UHealthComponentBase;
class UObject;
class UStatusEffect;
class UStatusEffectExclusiveKey;
UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class UStatusEffectsComponent : public UActorComponent {
    GENERATED_BODY()
    // UPROPERTY fields moved from protected section

public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TArray<FActiveStatusEffectBank> ActiveStatusEffects;
    
    TArray<FStatusEffectData> ActiveStatusEffectData;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, Transient, meta=(AllowPrivateAccess=true))
    UHealthComponentBase* OwnerHealth;
    TSet<UStatusEffectExclusiveKey*> ActiveExclusiveKeys;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool IgnoreAll;
    UStatusEffectsComponent(const FObjectInitializer& ObjectInitializer);
    UFUNCTION(BlueprintAuthorityOnly, BlueprintCallable)
    static bool TryPushActiveStatusEffectInstance(UStatusEffect* StatusEffect, AActor* Target, AActor* Owner);
    static bool TryPushActiveStatusEffect(TSubclassOf<UStatusEffect> StatusEffect, AActor* Target, AActor* Owner);
    static bool TryPopActiveStatusEffectInstance(UStatusEffect* StatusEffect, AActor* Target, AActor* Owner);
    static bool TryPopActiveStatusEffect(TSubclassOf<UStatusEffect> StatusEffect, AActor* Target, AActor* Owner);
    void ReapplyStatusEffectInstance(UStatusEffect* StatusEffect, AActor* Owner);
    bool PushActiveStatusEffectInstance(UStatusEffect* StatusEffect, AActor* Owner, int32 Stacks);
    bool PushActiveStatusEffect(TSubclassOf<UStatusEffect> StatusEffect, AActor* Owner, int32 Stacks);
    void PopAllActiveStatusEffectStacks(TSubclassOf<UStatusEffect> StatusEffect, AActor* Owner);
    void PopAllActiveStatusEffectsOfType(TSubclassOf<UStatusEffect> StatusEffect, AActor* Owner);
    void PopAllActiveStatusEffects(AActor* Owner);
    void PopAllActiveStatusEffectInstanceStacks(UStatusEffect* StatusEffect, AActor* Owner);
    bool PopActiveStatusEffectInstance(UStatusEffect* StatusEffect, AActor* Owner);
    bool PopActiveStatusEffect(TSubclassOf<UStatusEffect> StatusEffect, AActor* Owner);
    UFUNCTION(BlueprintCallable)
    void OnDeath(UHealthComponentBase* HealthComponent);
    UFUNCTION(BlueprintAuthorityOnly, BlueprintCallable, BlueprintPure)
    bool HasActiveEffect(TSubclassOf<UStatusEffect> StatusEffect) const;
    UFUNCTION(BlueprintCallable, BlueprintPure)
    int32 GetStackAmount(TSubclassOf<UStatusEffect> StatusEffect, AActor* Owner) const;
    int32 GetFullStackAmount(TSubclassOf<UStatusEffect> StatusEffect) const;
    static UStatusEffect* CreateStatusEffectInstance(TSubclassOf<UStatusEffect> StatusEffect, UObject* Owner);
};
