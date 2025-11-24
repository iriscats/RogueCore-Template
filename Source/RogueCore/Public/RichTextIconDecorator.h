#pragma once
#include "CoreMinimal.h"
#include "Runtime/UMG/Public/Components/RichTextBlockDecorator.h"
#include "RichIconRow.h"
#include "Templates/SubclassOf.h"
#include "RichTextIconDecorator.generated.h"

class URichIconWidget;
UCLASS(Abstract, Blueprintable, MinimalAPI)
class URichTextIconDecorator : public URichTextBlockDecorator {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FString Prefix;
    
    TSubclassOf<URichIconWidget> WidgetClass;
    TMap<FName, FRichIconRow> Icons;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    bool bEmbedToolTipText;
    URichTextIconDecorator();
    UFUNCTION(BlueprintCallable)
    void SetEmbedToolTipText(bool InEmbed);
};
