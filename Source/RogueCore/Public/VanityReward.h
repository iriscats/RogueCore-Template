#pragma once
#include "CoreMinimal.h"
#include "UnlockReward.h"
#include "VanityReward.generated.h"

class UPlayerCharacterID;
class UVanityItem;
UCLASS(Blueprintable, EditInlineNew)
class UVanityReward : public UUnlockReward {
    GENERATED_BODY()
    // UPROPERTY fields moved from protected section
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UVanityItem* VanityItem;
    
    UPlayerCharacterID* OptionalCharacterID;
    bool UseContextAsTargetCharacter;
    UVanityReward();
};
