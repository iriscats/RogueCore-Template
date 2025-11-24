#pragma once
#include "CoreMinimal.h"
#include "BioBoosterReward.generated.h"

class UBXEUnlockBase;
class UTexture2D;
USTRUCT(BlueprintType)
struct FBioBoosterReward {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FText Title;
    
    FText Description;
    UTexture2D* Icon;
    UBXEUnlockBase* Reward;
    int32 RewardIndex;
    ROGUECORE_API FBioBoosterReward();
};
