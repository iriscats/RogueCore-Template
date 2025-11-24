#pragma once
#include "CoreMinimal.h"
#include "ElementParams.h"
#include "NetDamagePartition.h"
#include "NetDamageInstance.generated.h"

USTRUCT(BlueprintType)
struct FNetDamageInstance {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FNetDamagePartition> Partitions;
    
    FElementParams ElementParams;
    float ArmorPiercing;
    float ArmorDamage;
    float WeakpointMultiplier;
    bool Notify;
    ROGUECORE_API FNetDamageInstance();
};
