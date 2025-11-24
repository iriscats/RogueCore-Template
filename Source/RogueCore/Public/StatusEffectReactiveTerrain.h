#pragma once
#include "CoreMinimal.h"
#include "ReactiveTerrain.h"
#include "Templates/SubclassOf.h"
#include "StatusEffectReactiveTerrain.generated.h"

class UStatusEffect;
UCLASS(Blueprintable)
class UStatusEffectReactiveTerrain : public UReactiveTerrain {
    GENERATED_BODY()
    // UPROPERTY fields moved from protected section

public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<UStatusEffect> StatusEffect;
    
    UStatusEffectReactiveTerrain();
};
