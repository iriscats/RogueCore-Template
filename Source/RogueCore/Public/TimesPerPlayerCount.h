#pragma once
#include "CoreMinimal.h"
#include "TimesPerPlayerCount.generated.h"

USTRUCT(BlueprintType)
struct FTimesPerPlayerCount {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float OnePlayer;

    float TwoPlayers;
    float ThreePlayers;
    float FourPlayers;
    ROGUECORE_API FTimesPerPlayerCount();
};
