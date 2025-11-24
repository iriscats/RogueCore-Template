#pragma once
#include "CoreMinimal.h"
#include "DamageBonusBase.h"
#include "Templates/SubclassOf.h"
#include "ExtendSTEDurationBonus.generated.h"

class UStatusEffect;
UCLASS(Blueprintable, EditInlineNew)
class UExtendSTEDurationBonus : public UDamageBonusBase {
    GENERATED_BODY()

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<UStatusEffect> StatusEffect;

    float AddedDuration;

public:
    UExtendSTEDurationBonus();
};
