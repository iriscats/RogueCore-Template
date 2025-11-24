#pragma once
#include "CoreMinimal.h"
#include "IntelChallengeProgression.generated.h"

USTRUCT(BlueprintType)
struct FIntelChallengeProgression {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 ValueAtStart;
    
    int32 ValueAtEnd;
    ROGUECORE_API FIntelChallengeProgression();
};
