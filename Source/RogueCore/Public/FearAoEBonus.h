#pragma once
#include "CoreMinimal.h"
#include "DamageBonusBase.h"
#include "FearAoEBonus.generated.h"

UCLASS(Blueprintable, EditInlineNew)
class UFearAoEBonus : public UDamageBonusBase {
    GENERATED_BODY()

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float FearFactor;

    float Range;

public:
    UFearAoEBonus();
};
