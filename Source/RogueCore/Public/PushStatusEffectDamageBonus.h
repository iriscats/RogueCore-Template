#pragma once
#include "CoreMinimal.h"
#include "DamageBonusBase.h"
#include "Templates/SubclassOf.h"
#include "PushStatusEffectDamageBonus.generated.h"

class UStatusEffect;
UCLASS(Blueprintable, EditInlineNew)
class UPushStatusEffectDamageBonus : public UDamageBonusBase {
    GENERATED_BODY()
    

public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<UStatusEffect> StatusEffect;
    
    float Chance;
    bool IgnoreArmorHit;
    bool ApplyToInstigator;
    UPushStatusEffectDamageBonus();
};
