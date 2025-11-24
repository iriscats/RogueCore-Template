#pragma once
#include "CoreMinimal.h"
#include "Styling/SlateColor.h"
#include "Runtime/SlateCore/Public/Fonts/SlateFontInfo.h"
#include "UMG/RichTextBlock.h"
#include "TextStyleOverride.h"
#include "RichTextStylable.generated.h"

UCLASS(Blueprintable)
class URichTextStylable : public URichTextBlock {
    GENERATED_BODY()
    // UPROPERTY fields moved from protected section

public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSlateFontInfo Font;
    
    FSlateColor FontColor;
    TMap<FName, FTextStyleOverride> Styles;
    URichTextStylable();
};
