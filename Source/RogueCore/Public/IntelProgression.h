#pragma once
#include "CoreMinimal.h"
#include "IntelChallengeProgression.h"
#include "Templates/SubclassOf.h"
#include "IntelProgression.generated.h"

class UIntelChallenge;
USTRUCT(BlueprintType)
struct FIntelProgression {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<TSubclassOf<UIntelChallenge>> CompletedChallenges;
    
    TMap<TSubclassOf<UIntelChallenge>, FIntelChallengeProgression> ProgressedChallenges;
    ROGUECORE_API FIntelProgression();
};
