#pragma once
#include "CoreMinimal.h"
#include "EInputInteraction.h"
#include "InputTranslationEntry.generated.h"

USTRUCT(BlueprintType)
struct FInputTranslationEntry {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EInputInteraction Interaction;
    
    FName InputName;
    int32 Axis;
    ROGUECORE_API FInputTranslationEntry();
};
