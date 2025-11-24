#pragma once
#include "CoreMinimal.h"
#include "UnlockReward.h"
#include "VictoryPoseReward.generated.h"

class UPlayerCharacterID;
class UVictoryPose;
UCLASS(Blueprintable, EditInlineNew)
class UVictoryPoseReward : public UUnlockReward {
    GENERATED_BODY()

public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UVictoryPose* VictoryPose;
    
    UPlayerCharacterID* OptionalCharacterID;
    UVictoryPoseReward();
};
