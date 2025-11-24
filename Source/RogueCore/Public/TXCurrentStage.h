#pragma once
#include "CoreMinimal.h"
#include "TXEnemyPool.h"
#include "TXRiskVector.h"
#include "TXCurrentStage.generated.h"

USTRUCT(BlueprintType)
struct FTXCurrentStage {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 Index;
    
    int32 timer_wave_count;
    bool is_final_stage;
    TArray<FTXEnemyPool> enemy_pool;
    TArray<FTXRiskVector> risk_vectors;
    ROGUECORE_API FTXCurrentStage();
};
