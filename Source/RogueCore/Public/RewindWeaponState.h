#pragma once
#include "CoreMinimal.h"
#include "RewindWeaponState.generated.h"

class AItem;
USTRUCT(BlueprintType)
struct FRewindWeaponState {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    AItem* Weapon;
    
    int32 Clip;
    int32 Reserve;
    ROGUECORE_API FRewindWeaponState();
};
