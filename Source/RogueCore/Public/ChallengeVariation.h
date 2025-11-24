#pragma once
#include "CoreMinimal.h"
#include "ChallengeVariation.generated.h"

USTRUCT(BlueprintType)
struct FChallengeVariation {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 NumberOfWins;
    
    int32 XPCompleteGain;
    int32 TokenGain;
    ROGUECORE_API FChallengeVariation();
};
