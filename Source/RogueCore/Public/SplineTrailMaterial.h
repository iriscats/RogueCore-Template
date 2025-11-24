#pragma once
#include "CoreMinimal.h"
#include "SplineTrailMaterial.generated.h"

class UMaterialInterface;
USTRUCT(BlueprintType)
struct FSplineTrailMaterial {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSoftObjectPtr<UMaterialInterface> Material;
    
    FName slotName;
    int32 SlotIndex;
    ROGUECORE_API FSplineTrailMaterial();
};
