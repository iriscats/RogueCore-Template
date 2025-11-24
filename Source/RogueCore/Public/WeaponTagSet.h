#pragma once
#include "CoreMinimal.h"
#include "WeaponTagSet.generated.h"

class UWeaponRangeTag;
class UWeaponTechTag;
class UWeaponTypeTag;
USTRUCT(BlueprintType)
struct FWeaponTagSet {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    UWeaponRangeTag* RangeTag;
    
    UWeaponTypeTag* TypeTag;
    UWeaponTechTag* TechTag;
    ROGUECORE_API FWeaponTagSet();
};
