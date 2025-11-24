#pragma once
#include "CoreMinimal.h"
#include "PlayerControllerLevelEndState.generated.h"

USTRUCT(BlueprintType)
struct FPlayerControllerLevelEndState {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool HasLevelEnded;
    
    bool IsMissionAborted;
    bool IsAllDwarvesDown;
    int32 NumberOfCompletedStages;
    ROGUECORE_API FPlayerControllerLevelEndState();
};
