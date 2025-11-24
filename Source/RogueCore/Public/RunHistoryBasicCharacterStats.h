#pragma once
#include "CoreMinimal.h"
#include "RunHistoryBasicCharacterStats.generated.h"

USTRUCT(BlueprintType)
struct ROGUECORE_API FRunHistoryBasicCharacterStats {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float MaxHealth;
    
    float MaxArmor;
    int32 TotalKills;
    int32 TotalRevived;
    int32 TotalDeaths;
    float TotalMineralsMined;
    float TotalHealthRestored;
    float TotalCappedDamage;
    float TotalOverkillDamage;
    FString CauseOfDeath;
    FRunHistoryBasicCharacterStats();
};
