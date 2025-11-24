#pragma once
#include "CoreMinimal.h"
#include "XPSettings.generated.h"

USTRUCT(BlueprintType)
struct FXPSettings {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float XP_PerGold;
    
    float XP_PerKill;
    float XP_OnSurvivedLevel;
    ROGUECORE_API FXPSettings();
};
