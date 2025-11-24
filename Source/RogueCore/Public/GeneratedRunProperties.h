#pragma once
#include "CoreMinimal.h"
#include "GeneratedRunProperties.generated.h"

class UMissionDNA;
USTRUCT(BlueprintType)
struct FGeneratedRunProperties {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UMissionDNA* RunDNA;
    
    float HazardBonus;
    ROGUECORE_API FGeneratedRunProperties();
};
