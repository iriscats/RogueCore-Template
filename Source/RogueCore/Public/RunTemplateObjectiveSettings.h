#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "RunTemplateObjectiveSettings.generated.h"

USTRUCT(BlueprintType)
struct FRunTemplateObjectiveSettings {
    GENERATED_BODY()
public:
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    FInt32Interval AmountOfSecondaryObjectives;
    
    FInt32Interval AmountOfExpeniteObjectives;
    ROGUECORE_API FRunTemplateObjectiveSettings();
};
