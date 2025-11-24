#pragma once
#include "CoreMinimal.h"
#include "EEnemyHealthScaling.h"
#include "EliteEnemyBan.h"
#include "Templates/SubclassOf.h"
#include "EliteEnemyEntry.generated.h"

class UActorComponent;
class UStatusEffect;
USTRUCT(BlueprintType)
struct FEliteEnemyEntry {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float HeroChance;
    
    TSubclassOf<UStatusEffect> StatusEffect;
    TArray<TSubclassOf<UActorComponent>> ComponentsToAdd;
    bool OverrideHealthScaling;
    TArray<FEliteEnemyBan> Bans;
    EEnemyHealthScaling HealthScalingOverride;
    ROGUECORE_API FEliteEnemyEntry();
};
