#pragma once
#include "CoreMinimal.h"
#include "StaggerParams.generated.h"

class APlayerCharacter;
USTRUCT(BlueprintType)
struct FStaggerParams {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float Duration;
    
    bool IgnoreMultipliers;
    APlayerCharacter* SourcePlayer;
    ROGUECORE_API FStaggerParams();
};
