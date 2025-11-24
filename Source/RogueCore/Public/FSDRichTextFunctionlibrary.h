#pragma once
#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "RichTextParseResult.h"
#include "FSDRichTextFunctionlibrary.generated.h"

UCLASS(Blueprintable)
class UFSDRichTextFunctionlibrary : public UBlueprintFunctionLibrary {
    GENERATED_BODY()
public:
    UFSDRichTextFunctionlibrary();
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static void SplitRichText(const FRichTextParseResult& Parser, int32 SplitIndex, bool bKeepLeftFormatting, bool bKeepRightFormatting, FText& OutLeftText, FText& OutRightText);
    
    static FText RemoveRichTextTags(const FText& InText);
    UFUNCTION(BlueprintCallable)
    static FRichTextParseResult ParseRichText(const FText& InText);
    static FText MidRichText(const FRichTextParseResult& Parser, int32 StartIndex, int32 count, bool bKeepFormatting);
};
