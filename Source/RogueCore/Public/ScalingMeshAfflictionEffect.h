#pragma once
#include "CoreMinimal.h"
#include "AfflictionEffect.h"
#include "EFrozenAfflictionType.h"
#include "ScalingMeshAfflictionItem.h"
#include "ScalingMeshAfflictionEffect.generated.h"

class UMaterialInterface;
UCLASS(Abstract, Blueprintable)
class UScalingMeshAfflictionEffect : public UAfflictionEffect {
    GENERATED_BODY()
    // UPROPERTY fields moved from protected section

public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EFrozenAfflictionType AfflictionType;
    
    TArray<FScalingMeshAfflictionItem> IceParts;
    UMaterialInterface* MaterialOverride;
    FName ParticleBone;
    TArray<UMaterialInterface*> IceMaterials;
    UScalingMeshAfflictionEffect();
};
