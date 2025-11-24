#pragma once
#include "CoreMinimal.h"
#include "UnlockReward.h"
#include "VanityCollectionReward.generated.h"

class UPlayerCharacterID;
class UVanityItem;
UCLASS(Blueprintable, EditInlineNew)
class UVanityCollectionReward : public UUnlockReward {
    GENERATED_BODY()
    // UPROPERTY fields moved from protected section

public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<UVanityItem*> VanityItems;
    
    UPlayerCharacterID* OptionalCharacterID;
    bool UseContextAsTargetCharacter;
    UVanityCollectionReward();
};
