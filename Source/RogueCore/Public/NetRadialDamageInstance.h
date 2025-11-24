#pragma once
#include "CoreMinimal.h"
#include "Engine/NetSerialization.h"
#include "ElementParams.h"
#include "NetDamagePartition.h"
#include "NetRadialDamageInstance.generated.h"

class AActor;
USTRUCT(BlueprintType)
struct FNetRadialDamageInstance {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FVector_NetQuantize Location;
    
    TArray<FNetDamagePartition> Partitions;
    FElementParams ElementParams;
    AActor* Target;
    float ArmorPiercing;
    float ArmorDamage;
    ROGUECORE_API FNetRadialDamageInstance();
};
