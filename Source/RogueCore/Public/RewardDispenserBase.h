#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "RewardDispenserBase.generated.h"

UCLASS(Blueprintable)
class ARewardDispenserBase : public AActor {
    GENERATED_BODY()
public:
    ARewardDispenserBase(const FObjectInitializer& ObjectInitializer);
};
