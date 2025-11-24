#pragma once
#include "CoreMinimal.h"
#include "AfflictionEffect.h"
#include "EFrozenAfflictionType.h"
#include "FrozenAfflictionEffect.generated.h"

class UMaterialInterface;
UCLASS(Abstract, Blueprintable)
class UFrozenAfflictionEffect : public UAfflictionEffect {
    GENERATED_BODY()
    // UPROPERTY fields moved from protected section

public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EFrozenAfflictionType AfflictionType;
    
    UMaterialInterface* MaterialOverride;
    TArray<UMaterialInterface*> IceMaterials;
    UFrozenAfflictionEffect();
};
