#pragma once
#include "CoreMinimal.h"
#include "Styling/SlateColor.h"
//#include "Styling/SlateFontInfo.h"  // Path not found in UE5.6
#include "TextStyleOverride.generated.h"

USTRUCT(BlueprintType)
struct FTextStyleOverride {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bOverrideFont;
    
    FSlateFontInfo Font;
    bool bOverrideColor;
    FSlateColor Color;
    bool bOverrideSize;
    float SizeScale;
    ROGUECORE_API FTextStyleOverride();
};
