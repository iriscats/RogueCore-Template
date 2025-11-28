#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Styling/SlateColor.h"
#include "Components/RichTextBlock.h"
#include "RichTextSizable.generated.h"

UCLASS(Blueprintable)
class URichTextSizable : public URichTextBlock {
    GENERATED_BODY()
    

public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bOverrideDefaultSize;
    
    int32 OverrideDefaultFontSize;
    bool bOverrideDefaultColor;
    FSlateColor OverrideDefaultFontColor;
    URichTextSizable();
    UFUNCTION(BlueprintCallable)
    void SetDefaultFontSize(int32 InFontSize);
    void SetDefaultFontColor(const FLinearColor& InColor);
};
