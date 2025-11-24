#pragma once
#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "Styling/SlateTypes.h"
#include "BasicTextStyle.h"
#include "BasicTextStyleLibrary.generated.h"

class UBasicTextStyleAsset;

UCLASS(Blueprintable)
class UBasicTextStyleLibrary : public UBlueprintFunctionLibrary {
    GENERATED_BODY()
public:
    UBasicTextStyleLibrary();

    UFUNCTION(BlueprintCallable, BlueprintPure)
    static FBasicTextStyle TextBlockStyleToBasicTextStyle(const FTextBlockStyle& InTextStyle);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static FTextBlockStyle BasicToTextBlockStyle(const FBasicTextStyle& InBasicTextStyle);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static FBasicTextStyle AssetToBasicColor(UBasicTextStyleAsset* InTextStyleAsset);
    
};

