#pragma once
#include "CoreMinimal.h"
#include "DamageInfo.generated.h"

USTRUCT(BlueprintType)
struct FDamageInfo {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float DamageInflicted;
    
    float BaseDamage;
    bool Critical;
    bool Weakpoint;
    bool Radial;
    float RadialRange;
    bool KillingBlow;
    ROGUECORE_API FDamageInfo();
};
