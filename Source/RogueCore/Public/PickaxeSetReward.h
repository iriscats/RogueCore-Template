#pragma once
#include "CoreMinimal.h"
#include "UnlockReward.h"
#include "PickaxeSetReward.generated.h"

class UPickaxePart;
UCLASS(Blueprintable, EditInlineNew)
class UPickaxeSetReward : public UUnlockReward {
    GENERATED_BODY()
    

public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UPickaxePart* BladeFront;
    
    UPickaxePart* OptionalBladeBack;
    UPickaxePart* Pommel;
    UPickaxePart* Handle;
    UPickaxePart* Shaft;
    UPickaxePart* Head;
    UPickaxePart* Material;
    UPickaxeSetReward();
};
