#pragma once
#include "CoreMinimal.h"
#include "ArmorDamageEffects.generated.h"

class UFXSystemAsset;
USTRUCT(BlueprintType)
struct FArmorDamageEffects {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<UFXSystemAsset*> ArmorBreakParticles;
    
    TArray<UFXSystemAsset*> DissolveParticles;
    TArray<UFXSystemAsset*> BeamParticles;
    ROGUECORE_API FArmorDamageEffects();
};
