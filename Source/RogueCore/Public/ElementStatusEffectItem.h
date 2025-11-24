#pragma once
#include "CoreMinimal.h"
#include "ElementParams.h"
#include "RandRange.h"
#include "StatusEffectItem.h"
#include "ElementStatusEffectItem.generated.h"

class UElementType;
UCLASS(Blueprintable, EditInlineNew)
class UElementStatusEffectItem : public UStatusEffectItem {
    GENERATED_BODY()
    // UPROPERTY fields moved from protected section

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UElementType* ElementType;

    FRandRange ValueChangeAmount;

    FElementParams Params;

public:
    UElementStatusEffectItem();
};
