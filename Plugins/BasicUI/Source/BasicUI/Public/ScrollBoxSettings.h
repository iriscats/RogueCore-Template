#pragma once
#include "CoreMinimal.h"
#include "Layout/Margin.h" 
#include "Styling/SlateTypes.h"
#include "Runtime/Slate/Public/Framework/Styling/ScrollBoxWidgetStyle.h"
#include "ScrollBoxSettings.generated.h"

USTRUCT(BlueprintType)
struct BASICUI_API FScrollBoxSettings {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FScrollBoxStyle Style;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FScrollBarStyle ScrollBarStyle;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FMargin ContentPadding;
    
    FScrollBoxSettings();
};

