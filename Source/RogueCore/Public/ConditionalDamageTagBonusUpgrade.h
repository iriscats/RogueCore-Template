#pragma once
#include "CoreMinimal.h"
#include "ItemUpgrade.h"
#include "ConditionalDamageTagBonusUpgrade.generated.h"

class UDamageCondition;
class UDamageTag;
UCLASS(Blueprintable, EditInlineNew, MinimalAPI)
class UConditionalDamageTagBonusUpgrade : public UItemUpgrade {
    GENERATED_BODY()
    

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))

    UDamageCondition* Condition;

    UConditionalDamageTagBonusUpgrade();

};
