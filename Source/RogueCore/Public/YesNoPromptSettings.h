#pragma once
#include "CoreMinimal.h"
#include "Templates/SubclassOf.h"
#include "YesNoPromptSettings.generated.h"

class UYesNoPromptWidget;
USTRUCT(BlueprintType)
struct FYesNoPromptSettings {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<UYesNoPromptWidget> WidgetClass;
    
    int32 ZOrder;
    FText Title;
    FText Message;
    ROGUECORE_API FYesNoPromptSettings();
};
