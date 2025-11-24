#pragma once
#include "CoreMinimal.h"
#include "EDamageType.h"
#include "EEnemyAttackType.h"
#include "EnemyAttackDescription.generated.h"

USTRUCT(BlueprintType)
struct FEnemyAttackDescription {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FText Name;
    
    EEnemyAttackType Range;
    EDamageType DamageType;
    ROGUECORE_API FEnemyAttackDescription();
};
