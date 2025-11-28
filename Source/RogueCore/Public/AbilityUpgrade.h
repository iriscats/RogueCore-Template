#pragma once
#include "CoreMinimal.h"
#include "EAbilityAmountType.h"
#include "StandardItemUpgrade.h"
#include "AbilityUpgrade.generated.h"

UCLASS(Abstract, Blueprintable, EditInlineNew)
class UAbilityUpgrade : public UStandardItemUpgrade {
    GENERATED_BODY()
    

public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EAbilityAmountType AmountType;
    
    UAbilityUpgrade();
};
