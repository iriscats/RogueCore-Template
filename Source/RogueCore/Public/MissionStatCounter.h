#pragma once
#include "CoreMinimal.h"

#include "MissionStatCounter.generated.h"

USTRUCT(BlueprintType)
struct FMissionStatCounter {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGuid PlayerClassID;
    
    FGuid MissionStatID;
    float Value;
    ROGUECORE_API FMissionStatCounter();
};
