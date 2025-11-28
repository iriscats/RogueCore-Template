#pragma once
#include "CoreMinimal.h"
#include "UnlockReward.h"
#include "UnlockDifficultyReward.generated.h"

class UDifficultySetting;
UCLASS(Blueprintable, EditInlineNew)
class UUnlockDifficultyReward : public UUnlockReward {
    GENERATED_BODY()
    
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UDifficultySetting* Difficulty;
    
    UUnlockDifficultyReward();
};
