#pragma once
#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "BXEMissionStatSettings.generated.h"

class UBXEMissionStat;
UCLASS(Blueprintable)
class ROGUECORE_API UBXEMissionStatSettings : public UDataAsset {
    GENERATED_BODY()
    // UPROPERTY fields moved from protected section
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UBXEMissionStat* MidStationReached;
    
    UBXEMissionStat* stageCompleted;
    UBXEMissionStat* RunCompleted_All;
    UBXEMissionStat* EnemyKilledWithPowerAttack;
    UBXEMissionStatSettings();
};
