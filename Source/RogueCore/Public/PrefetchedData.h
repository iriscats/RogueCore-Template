#pragma once
#include "CoreMinimal.h"
#include "DamageBonuses.h"
#include "PrefetchedData.generated.h"

USTRUCT(BlueprintType)
struct FPrefetchedData {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FDamageBonuses> PrefetchedBonuses;
    
    float PrefetchedCritChance;
    int32 ClipCount;
    bool IsInitialized;
    ROGUECORE_API FPrefetchedData();
};
