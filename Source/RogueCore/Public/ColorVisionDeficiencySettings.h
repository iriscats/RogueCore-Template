#pragma once
#include "CoreMinimal.h"
#include "UObject/UnrealType.h"
#include "ColorVisionDeficiencySettings.generated.h"

USTRUCT(BlueprintType)
struct FColorVisionDeficiencySettings {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EColorVisionDeficiency Type;
    
    float Severity;
    ROGUECORE_API FColorVisionDeficiencySettings();
};
