#pragma once
#include "CoreMinimal.h"

#include "ChallengeSaveInfo.generated.h"

USTRUCT(BlueprintType)
struct FChallengeSaveInfo {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<int32> StatIndices;
    
    FGuid ChallengeGuid;
    int32 CurrentWins;
    int32 NumberOfWins;
    int32 XPCompleteGain;
    int32 TokenGain;
    ROGUECORE_API FChallengeSaveInfo();
};
