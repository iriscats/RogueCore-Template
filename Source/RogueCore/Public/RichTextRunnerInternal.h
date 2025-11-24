#pragma once
#include "CoreMinimal.h"
#include "Styling/SlateTypes.h"
#include "UMG/RichTextBlock.h"
#include "RichTextRunnerInternal.generated.h"

UCLASS(Blueprintable)
class URichTextRunnerInternal : public URichTextBlock {
    GENERATED_BODY()
    // UPROPERTY fields moved from protected section

public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TArray<FTextBlockStyle> CachedTextStyles;
    
    URichTextRunnerInternal();
};
