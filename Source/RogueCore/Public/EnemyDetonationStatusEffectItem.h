#pragma once
#include "CoreMinimal.h"
#include "StatusEffectItem.h"
#include "EnemyDetonationStatusEffectItem.generated.h"

UCLASS(Blueprintable, Deprecated, EditInlineNew, NotPlaceable)
class UDEPRECATED_EnemyDetonationStatusEffectItem : public UStatusEffectItem {
    GENERATED_BODY()

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool FireDetonation;

    bool IceDetonation;

public:
    UDEPRECATED_EnemyDetonationStatusEffectItem();
};
