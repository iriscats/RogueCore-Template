#pragma once
#include "CoreMinimal.h"
#include "Mutator.h"
#include "DifficultyMutator.generated.h"

UCLASS(Blueprintable, EditInlineNew)
class UDifficultyMutator : public UMutator {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float ExtraLargeEnemyDamageResistanceMultiplier;
    
    float EnemyDamageResistanceMultiplier;
    float SmallEnemyDamageResistanceMultiplier;
    float EnemyDamageModifierMultiplier;
    float EnemyCountModifierMultiplier;
    float WeakpointDamageMultiplier;
    float HazardBonus;
    float ProjectileSpeedModifier;
    float AttackCooldownModifier;
    float SpeedModifier;
    UDifficultyMutator();
};
