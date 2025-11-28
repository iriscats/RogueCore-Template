#pragma once
#include "CoreMinimal.h"

#include "Engine/DataAsset.h"
#include "GymActivityStats.generated.h"

UCLASS(Blueprintable)
class UGymActivityStats : public UDataAsset {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FVector2D SpeedMinMax;
    
    float SpeedIncreaseInterval;
    float HalfRepSpeedModifier;
    float BaseRepTime;
    float MinRepTime;
    float RepTimeDifficultyIncrease;
    float MontagePlayRateDifficultyIncrease;
    float MaxMontagePlayRate;
    int32 MaxLives;
    int32 DifficultyIncreaseInterval;
    int32 TotalReps;
    UGymActivityStats();
};
