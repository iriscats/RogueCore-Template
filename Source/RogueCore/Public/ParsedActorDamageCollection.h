#pragma once
#include "CoreMinimal.h"
#include "DamageValues.h"
#include "ParsedActorDamageCollection.generated.h"

class UDamageClass;
class UTexture2D;
USTRUCT(BlueprintType)
struct FParsedActorDamageCollection {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FString Name;
    
    UTexture2D* Icon;
    FDamageValues TotalDamageDealt;
    FDamageValues TotalDamageTaken;
    int32 WeakPointHitsDealt;
    int32 CriticalHitsDealt;
    TMap<UDamageClass*, FDamageValues> DamageDealtPartitions;
    TMap<UDamageClass*, FDamageValues> DamageTakenPartitions;
    ROGUECORE_API FParsedActorDamageCollection();
};
