#pragma once
#include "CoreMinimal.h"
#include "CharacterProgress.h"
#include "PlayerProgress.h"
#include "EndMissionResult.generated.h"

class USchematic;
USTRUCT(BlueprintType)
struct FEndMissionResult {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FPlayerProgress PreviousPlayerProgress;
    
    FPlayerProgress PlayerProgress;
    FCharacterProgress PreviousCharacterProgress;
    FCharacterProgress CharacterProgress;
    USchematic* RewardedSchematic;
    bool bReadyForUse;
    ROGUECORE_API FEndMissionResult();
};
