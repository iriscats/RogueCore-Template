#pragma once
#include "CoreMinimal.h"
#include "Styling/SlateBrush.h"
#include "ButtonHoldSettings.generated.h"

USTRUCT(BlueprintType)
struct FButtonHoldSettings {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSlateBrush ProgressBrush;
    
    FName ProgressMaterialParam;
    float HoldDuration;
    ROGUECORE_API FButtonHoldSettings();
};
