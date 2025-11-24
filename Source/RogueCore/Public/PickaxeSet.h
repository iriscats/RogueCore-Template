#pragma once
#include "CoreMinimal.h"
#include "PickaxeSet.generated.h"

class UPickaxePart;
USTRUCT(BlueprintType)
struct FPickaxeSet {
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
    ROGUECORE_API FPickaxeSet();
};
