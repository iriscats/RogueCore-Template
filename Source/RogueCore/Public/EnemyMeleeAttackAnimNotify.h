#pragma once
#include "CoreMinimal.h"
#include "Runtime/Engine/Classes/Animation/AnimNotifies/AnimNotify.h"
#include "EnemyMeleeAttackAnimNotify.generated.h"

UCLASS(Blueprintable, CollapseCategories)
class UEnemyMeleeAttackAnimNotify : public UAnimNotify {
    GENERATED_BODY()

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName AttackTag;

public:
    UEnemyMeleeAttackAnimNotify();
};
