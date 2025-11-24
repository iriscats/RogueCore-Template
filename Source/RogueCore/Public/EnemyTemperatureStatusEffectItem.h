#pragma once
#include "CoreMinimal.h"
#include "StatusEffectItem.h"
#include "EnemyTemperatureStatusEffectItem.generated.h"

UCLASS(Blueprintable, Deprecated, EditInlineNew, NotPlaceable)
class UDEPRECATED_EnemyTemperatureStatusEffectItem : public UStatusEffectItem {
    GENERATED_BODY()

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float WarmingRate;

    float UnFreezeTemperature;

    float TemperatureChangeScaleModifier;

public:
    UDEPRECATED_EnemyTemperatureStatusEffectItem();
};
