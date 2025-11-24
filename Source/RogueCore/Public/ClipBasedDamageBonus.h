#pragma once
#include "CoreMinimal.h"
#include "DamageBonusBase.h"
#include "EDamageBonusType.h"
#include "ClipBasedDamageBonus.generated.h"

class UDamageClass;
UCLASS(Blueprintable, EditInlineNew)
class UClipBasedDamageBonus : public UDamageBonusBase {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UDamageClass* DamageClass;
    
    float BuffAmount;
    EDamageBonusType Type;
    bool InvertBonus;
    UClipBasedDamageBonus();
};
