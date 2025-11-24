#pragma once
#include "CoreMinimal.h"
#include "DamageCondition.h"
#include "MultiDamageCondition.generated.h"

UCLASS(Blueprintable, EditInlineNew)
class UMultiDamageCondition : public UDamageCondition {
    GENERATED_BODY()
    // UPROPERTY fields moved from protected section
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    TArray<UDamageCondition*> Conditions;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool RequireAllTrue;
    UMultiDamageCondition();
};
