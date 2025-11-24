#pragma once
#include "CoreMinimal.h"
#include "WaveEntry.generated.h"

class UEnemyWaveController;
USTRUCT(BlueprintType)
struct FWaveEntry {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float Weight;
    
protected:
    TSoftClassPtr<UEnemyWaveController> WaveController;
    ROGUECORE_API FWaveEntry();
};
