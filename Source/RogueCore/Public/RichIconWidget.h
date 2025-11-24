#pragma once
#include "CoreMinimal.h"
#include "Styling/SlateBrush.h"
#include "Blueprint/UserWidget.h"
#include "RichIconWidget.generated.h"

UCLASS(Abstract, Blueprintable, EditInlineNew)
class URichIconWidget : public UUserWidget {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSlateBrush IconBrush;
    
    FText IconToolTipText;
    bool bEmbedToolTipText;
    URichIconWidget();
};
