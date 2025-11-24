#pragma once
#include "CoreMinimal.h"
#include "UObject/UnrealType.h"
#include "Layout/Margin.h" 
#include "Components/TextBlock.h"
#include "FSDLabelWidget.generated.h"

UCLASS(Blueprintable)
class UFSDLabelWidget : public UTextBlock {
    GENERATED_BODY()
public:
    UFSDLabelWidget();
    UFUNCTION(BlueprintCallable)
    void SetWrapTextAt(float WrapAt);
    
    void SetWrappingPolicy(ETextWrappingPolicy Policy);
    void SetMargin(FMargin NewMargin);
    void SetLineHeightPercentage(float percentage);
    void SetFontSize(int32 Size);
    UFUNCTION(BlueprintCallable, BlueprintPure)
    int32 GetFontSize() const;
};
