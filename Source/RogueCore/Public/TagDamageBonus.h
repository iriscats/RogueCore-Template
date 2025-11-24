#pragma once
#include "CoreMinimal.h"
#include "DamageBonusBase.h"
#include "TagDamageBonus.generated.h"

class UDamageTag;
UCLASS(Blueprintable, EditInlineNew)
class UTagDamageBonus : public UDamageBonusBase {
    GENERATED_BODY()
    // UPROPERTY fields moved from protected section

public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<UDamageTag*> Tags;
    
    UTagDamageBonus();
};
