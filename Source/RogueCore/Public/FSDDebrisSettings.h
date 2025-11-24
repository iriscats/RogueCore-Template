#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "FSDDebrisSettings.generated.h"

UCLASS(Blueprintable, DefaultConfig, Config=Game)
class UFSDDebrisSettings : public UDeveloperSettings {
    GENERATED_BODY()
    // UPROPERTY fields moved from protected section

public:
    UPROPERTY(BlueprintReadWrite, Config, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSoftObjectPath DefaultInfluencerDensityCurve;
    
    FSoftObjectPath DefaultInfluencerSizeCurve;
    UFSDDebrisSettings();
};
