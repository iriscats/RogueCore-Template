#pragma once
#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "Styling/SlateBrush.h"
#include "BasicBrush.h"
#include "BasicBrushLibrary.generated.h"

class UBasicBrushAsset;

UCLASS(Blueprintable)
class UBasicBrushLibrary : public UBlueprintFunctionLibrary {
    GENERATED_BODY()
public:
    UBasicBrushLibrary();

    UFUNCTION(BlueprintCallable, BlueprintPure)
    static FBasicBrush SlateToBasicBrush(const FSlateBrush& InBrush);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static FSlateBrush BasicToSlateBrush(const FBasicBrush& InBasicBrush);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static FBasicBrush AssetToBasicBrush(UBasicBrushAsset* InAsset);
    
};

