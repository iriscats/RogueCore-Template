#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "RewindWeaponState.h"
#include "RewindData.generated.h"

USTRUCT(BlueprintType)
struct FRewindData {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FTransform Transform;
    
    FVector Velocity;
    TArray<FRewindWeaponState> WeaponStates;
    float Health;
    float Armor;
    float TempHealth;
    float PowerAttackCooldown;
    ROGUECORE_API FRewindData();
};
