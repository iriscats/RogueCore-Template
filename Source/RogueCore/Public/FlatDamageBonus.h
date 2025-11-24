#pragma once
#include "CoreMinimal.h"
#include "DamageBonusBase.h"
#include "FlatDamageBonus.generated.h"

class UDamageClass;
UCLASS(Blueprintable, EditInlineNew)
class UFlatDamageBonus : public UDamageBonusBase {
    GENERATED_BODY()

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float Damage;

    UDamageClass* DamageClass;

public:
    UFlatDamageBonus();
};
