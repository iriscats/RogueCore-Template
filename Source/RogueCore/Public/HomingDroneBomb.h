#pragma once
#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "Projectile.h"
#include "HomingDroneBomb.generated.h"

class UEnemyHealthComponent;
class USoundCue;
UCLASS(Blueprintable)
class AHomingDroneBomb : public AProjectile {
    GENERATED_BODY()
    
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UEnemyHealthComponent* Health;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    USoundCue* ArmingSound;
    float HomingUpdateInterval;
    float TargetSearchInterval;
    float ArmTime;
    FGameplayTagContainer GameplayTags;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, ReplicatedUsing=OnRep_HomingAccelerationMagnitude, meta=(AllowPrivateAccess=true))
    float HomingAccelerationMagnitude;
    AHomingDroneBomb(const FObjectInitializer& ObjectInitializer);
    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
    UFUNCTION(BlueprintCallable)
    void UpdateHomingSpeed();
    void SearchForTarget();
    UFUNCTION()
    void OnRep_HomingAccelerationMagnitude();
    bool HasMatchingGameplayTag(FGameplayTag TagToCheck) const { return GameplayTags.HasTag(TagToCheck); }
    bool HasAnyMatchingGameplayTags(const FGameplayTagContainer& TagContainer) const { return GameplayTags.HasAny(TagContainer); }
    bool HasAllMatchingGameplayTags(const FGameplayTagContainer& TagContainer) const { return GameplayTags.HasAll(TagContainer); }
    FGameplayTagContainer BP_GetOwnedGameplayTags() const { return GameplayTags; }
};
