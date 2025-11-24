#pragma once
#include "CoreMinimal.h"
#include "RunHistoryBasicCooperStats.generated.h"

USTRUCT(BlueprintType)
struct ROGUECORE_API FRunHistoryBasicCooperStats {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 TotalMachineGunKills;
    
    int32 TotalRocketKills;
    int32 TotalRevived;
    float TotalDamage;
    float TotalOverkill;
    FRunHistoryBasicCooperStats();
};
