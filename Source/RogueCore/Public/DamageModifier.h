#pragma once
#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "DamageModifierItem.h"
#include "DamageModifier.generated.h"

class UDamageCondition;
UCLASS(Blueprintable, EditInlineNew)
class UDamageModifier : public UDataAsset {
    GENERATED_BODY()
    // UPROPERTY fields moved from protected section

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))

    TArray<FDamageModifierItem> Modifiers;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UDamageCondition* Condition;

    UDamageModifier();

};
