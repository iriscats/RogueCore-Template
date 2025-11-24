#pragma once
#include "CoreMinimal.h"
#include "EWeaponOverviewModifierType.h"
#include "EWeaponOverviewUnitType.h"
#include "WeaponOverviewAttributeEntryData.generated.h"

USTRUCT(BlueprintType)
struct ROGUECORE_API FWeaponOverviewAttributeEntryData {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float amount;
    
    EWeaponOverviewUnitType Unit;
    EWeaponOverviewModifierType ModifierType;
    bool IsHidden;
    FWeaponOverviewAttributeEntryData();
};
