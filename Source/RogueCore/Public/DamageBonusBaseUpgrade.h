#pragma once
#include "CoreMinimal.h"
#include "ItemUpgrade.h"
#include "DamageBonusBaseUpgrade.generated.h"

class UDamageCondition;
UCLASS(Abstract, Blueprintable, EditInlineNew, MinimalAPI)
class UDamageBonusBaseUpgrade : public UItemUpgrade {
    GENERATED_BODY()
    // UPROPERTY fields moved from protected section
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool UseBaseDamage;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UDamageCondition* Condition;
    UDamageBonusBaseUpgrade();
};
