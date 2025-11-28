#pragma once
#include "CoreMinimal.h"

#include "DamageCondition.h"
#include "MaterialDamageMultiplierCondition.generated.h"

UCLASS(Blueprintable, EditInlineNew)
class UMaterialDamageMultiplierCondition : public UDamageCondition {
    GENERATED_BODY()
    
public:
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    FFloatInterval MultiplierRangeRequired;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool Invert;
    UMaterialDamageMultiplierCondition();
};
