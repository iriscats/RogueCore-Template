#pragma once
#include "CoreMinimal.h"
#include "EDamageVector.h"
#include "NetDamagePartition.generated.h"

class UDamageClass;
USTRUCT(BlueprintType)
struct FNetDamagePartition {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EDamageVector DamageVector;
    
    UDamageClass* Type;
    float amount;
    float FearChance;
    float StaggerChance;
    ROGUECORE_API FNetDamagePartition();
};
