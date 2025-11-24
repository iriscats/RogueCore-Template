#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "Styling/SlateColor.h"
#include "BasicColor.h"
#include "BasicColorLibrary.generated.h"

class UBasicColorAsset;

UCLASS(Blueprintable)
class UBasicColorLibrary : public UBlueprintFunctionLibrary {
    GENERATED_BODY()
public:
    UBasicColorLibrary();

    UFUNCTION(BlueprintCallable, BlueprintPure)
    static FBasicColor LinearToBasicColor(const FLinearColor& InColor);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static FSlateColor BasicToSlateColor(const FBasicColor& InBasicColor);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static FLinearColor BasicToLinearColor(const FBasicColor& InBasicColor);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static FLinearColor AssetToLinearColor(UBasicColorAsset* InReferenceColor);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static FBasicColor AssetToBasicColor(UBasicColorAsset* InReferenceColor);
    
};

