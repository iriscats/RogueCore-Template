#pragma once
#include "CoreMinimal.h"
#include "DamageBonusEntry.h"
#include "DamageBonuses.generated.h"

class UDamageClass;
USTRUCT(BlueprintType)
struct FDamageBonuses {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<UDamageClass*, float> OtherDamages;
    
    TArray<FDamageBonusEntry> DynamicBonuses;
    ROGUECORE_API FDamageBonuses();
};
