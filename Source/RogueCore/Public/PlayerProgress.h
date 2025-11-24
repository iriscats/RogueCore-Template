#pragma once
#include "CoreMinimal.h"
#include "PlayerProgress.generated.h"

USTRUCT(BlueprintType)
struct FPlayerProgress {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 PlayerRank;

    int32 PlayerStars;
    ROGUECORE_API FPlayerProgress();
};
