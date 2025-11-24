#pragma once
#include "CoreMinimal.h"
#include "DamageModifierItem.h"
#include "ItemUpgrade.h"
#include "Templates/SubclassOf.h"
#include "UpgradeValues.h"
#include "ConditionalDamageModifierUpgrade.generated.h"

class AActor;
class AFSDPlayerState;
class UDamageCondition;
UCLASS(Blueprintable, EditInlineNew, MinimalAPI)
class UConditionalDamageModifierUpgrade : public UItemUpgrade {
    GENERATED_BODY()
    // UPROPERTY fields moved from protected section
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UDamageCondition* Condition;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FDamageModifierItem> Modifiers;
    UConditionalDamageModifierUpgrade();
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static FUpgradeValues GetUpgradedValue(TSubclassOf<AActor> Item, AFSDPlayerState* Player);
};
