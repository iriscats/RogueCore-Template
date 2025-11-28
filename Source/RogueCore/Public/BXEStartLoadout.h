#pragma once
#include "CoreMinimal.h"

#include "BXEStartLoadout.generated.h"

USTRUCT(BlueprintType)
struct FBXEStartLoadout {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGuid StartingWeapon;
    
    FGuid StartingSuit;
    ROGUECORE_API FBXEStartLoadout();
};
