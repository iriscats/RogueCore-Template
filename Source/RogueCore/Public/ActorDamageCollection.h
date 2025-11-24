#pragma once
#include "CoreMinimal.h"
#include "PartitionedDamageValues.h"
#include "ActorDamageCollection.generated.h"

USTRUCT(BlueprintType)
struct FActorDamageCollection {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FString Name;
    
    int32 WeakPointHitsDealt;
    int32 CriticalHitsDealt;
    TArray<FPartitionedDamageValues> DamageDealtPartitions;
    TArray<FPartitionedDamageValues> DamageTakenPartitions;
    ROGUECORE_API FActorDamageCollection();
};
