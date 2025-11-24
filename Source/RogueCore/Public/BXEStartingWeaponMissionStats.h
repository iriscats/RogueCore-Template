#pragma once
#include "CoreMinimal.h"
#include "BXEStartingWeaponMissionStats.generated.h"

class UMissionStat;
USTRUCT(BlueprintType)
struct FBXEStartingWeaponMissionStats {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UMissionStat* ReachedMidstation;
    
    UMissionStat* CompletedRun;
    ROGUECORE_API FBXEStartingWeaponMissionStats();
};
