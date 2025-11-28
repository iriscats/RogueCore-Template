#pragma once
#include "CoreMinimal.h"
#include "Styling/SlateColor.h"
#include "Runtime/SlateCore/Public/Fonts/SlateFontInfo.h"
#include "Components/RichTextBlock.h"
#include "TextStyleOverride.h"
#include "RichTextStylable.generated.h"

UCLASS(Blueprintable)
class URichTextStylable : public URichTextBlock {
    GENERATED_BODY()
    

public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSlateFontInfo Font;
    
    FSlateColor FontColor;
    TMap<FName, FTextStyleOverride> Styles;
    URichTextStylable();
};
