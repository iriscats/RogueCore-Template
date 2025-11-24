#pragma once
#include "CoreMinimal.h"
#include "CustomRichTextDecorator.h"
#include "Templates/SubclassOf.h"
#include "RichTextInputDecorator.generated.h"

class URichTextInputWidget;
UCLASS(Abstract, Blueprintable, HideDropdown)
class URichTextInputDecorator : public UCustomRichTextDecorator {
    GENERATED_BODY()
    // UPROPERTY fields moved from protected section
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<URichTextInputWidget> DecoratorWidgetClass;
    
    URichTextInputDecorator();
};
