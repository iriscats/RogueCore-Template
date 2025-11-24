#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Curve2DAppearance.generated.h"

USTRUCT(BlueprintType)
struct FCurve2DAppearance {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float Thickness;
    
    FLinearColor Tint;
    float OutlineThickness;
    FLinearColor OutlineTint;
    ROGUECORE_API FCurve2DAppearance();
};
