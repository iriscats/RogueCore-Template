#pragma once
#include "CoreMinimal.h"
#include "RewindWeaponState.generated.h"

class AItem; 

USTRUCT(BlueprintType)
struct ROGUECORE_API FRewindWeaponState {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    AItem* Weapon; 

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 Clip;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 Reserve;

    FRewindWeaponState();
};