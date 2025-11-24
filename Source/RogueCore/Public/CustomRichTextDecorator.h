#pragma once
#include "CoreMinimal.h"
#include "Runtime/UMG/Public/Components/RichTextBlockDecorator.h"
#include "CustomRichTextDecorator.generated.h"

class URichTextBlock;
UCLASS(Abstract, Blueprintable, HideDropdown)
class UCustomRichTextDecorator : public URichTextBlockDecorator {
    GENERATED_BODY()
    // UPROPERTY fields moved from protected section
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, Transient, meta=(AllowPrivateAccess=true))
    URichTextBlock* RichTextBlock;
    
    UCustomRichTextDecorator();
};
