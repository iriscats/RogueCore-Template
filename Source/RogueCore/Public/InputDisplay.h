#pragma once
#include "CoreMinimal.h"

#include "EInputInteraction.h"
#include "InputDisplay.generated.h"

class UTexture2D;
USTRUCT(BlueprintType)
struct FInputDisplay {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EInputInteraction Interaction;
    
    FText InputText;
    FLinearColor TextTint;
    UTexture2D* Icon;
    bool IconTintable;
    ROGUECORE_API FInputDisplay();
};
