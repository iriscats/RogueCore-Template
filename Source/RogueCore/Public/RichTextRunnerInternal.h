#pragma once
#include "CoreMinimal.h"
#include "Styling/SlateTypes.h"
#include "Components/RichTextBlock.h"
#include "RichTextRunnerInternal.generated.h"

UCLASS(Blueprintable)
class URichTextRunnerInternal : public URichTextBlock {
    GENERATED_BODY()
    

public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TArray<FTextBlockStyle> CachedTextStyles;
    
    URichTextRunnerInternal();
};
