#pragma once
#include "CoreMinimal.h"
#include "SoftMissionStepDescription.h"
#include "MissionTypeDescription.generated.h"

USTRUCT(BlueprintType)
struct FMissionTypeDescription {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FText InfoHeadline;
    
    TArray<FSoftMissionStepDescription> Steps;
    ROGUECORE_API FMissionTypeDescription();
};
