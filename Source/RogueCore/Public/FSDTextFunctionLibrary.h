#pragma once
#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "FSDTextFunctionLibrary.generated.h"

UCLASS(Blueprintable)
class UFSDTextFunctionLibrary : public UBlueprintFunctionLibrary {
    GENERATED_BODY()
public:
    UFSDTextFunctionLibrary();
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static FText TextFromInt(float Value, int32 MinimumDigits);
    
    static FText TextFromFloat(float Value, int32 FractionalDigits);
    static FText TextAsPercentage(float Value, int32 MaxFractionalDigits);
    static FText AppendTextNewLine(const FText& Text1, const FText& Text2);
    static FText AppendTextDoubleNewLine(const FText& Text1, const FText& Text2);
    static FText AppendText(const FText& Text1, const FText& Text2, const FText& Delimiter);
};
