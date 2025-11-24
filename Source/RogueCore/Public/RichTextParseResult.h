#pragma once
#include "CoreMinimal.h"
#include "RichTextToken.h"
#include "RichTextParseResult.generated.h"

USTRUCT(BlueprintType)
struct FRichTextParseResult {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FText SourceText;
    
    FString UnformattedString;
    int32 UnformattedLength;
    TArray<FRichTextToken> Tokens;
    ROGUECORE_API FRichTextParseResult();
};
