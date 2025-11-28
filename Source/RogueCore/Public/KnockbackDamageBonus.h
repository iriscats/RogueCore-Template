#pragma once
#include "CoreMinimal.h"
#include "DamageBonusBase.h"
#include "KnockbackDamageBonus.generated.h"

UCLASS(Blueprintable, EditInlineNew)
class UKnockbackDamageBonus : public UDamageBonusBase {
    GENERATED_BODY()
    

public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float KnockBackHorizontalForce;
    
    float KnockBackVerticalForce;
    float VerticalScaleMultiplier;
    float HorizontalScaleMultiplier;
    float MinVerticalPower;
    float MinHorizontalPower;
    float OptimalDistance;
    bool AllowForIncapacitadedPlayes;
    bool KnockThowardsInstigator;
    bool ScalePowerToInstigatorDistance;
    bool AbsoluteKnockBack;
    UKnockbackDamageBonus();
};
