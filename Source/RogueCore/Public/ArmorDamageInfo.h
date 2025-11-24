#pragma once
#include "CoreMinimal.h"
#include "EArmorDamageType.h"
#include "ArmorDamageInfo.generated.h"

USTRUCT(BlueprintType)
struct FArmorDamageInfo {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 ArmorIndexMask;
    
    EArmorDamageType BreakType;
    ROGUECORE_API FArmorDamageInfo();
};
