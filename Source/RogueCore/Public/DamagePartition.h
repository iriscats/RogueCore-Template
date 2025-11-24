#pragma once
#include "CoreMinimal.h"
#include "DamagePartition.generated.h"

USTRUCT(BlueprintType)
struct FDamagePartition {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FString Type;
    
    float TotalDamage;
    float Damage;
    ROGUECORE_API FDamagePartition();
};
