#pragma once
#include "CoreMinimal.h"

#include "VictoryPoseSave.generated.h"

USTRUCT(BlueprintType)
struct FVictoryPoseSave {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGuid EquippedVictoryPose;

    TArray<FGuid> UnlockedVictoryPoses;

    ROGUECORE_API FVictoryPoseSave();
 
    TArray<FGuid> EquippedVictoryPoses;
};
