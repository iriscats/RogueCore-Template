#pragma once
#include "CoreMinimal.h"

#include "FSDDebrisSettings.generated.h"

UCLASS(Blueprintable, DefaultConfig, Config=Game)
class UFSDDebrisSettings : public UDeveloperSettings {
    GENERATED_BODY()
    

public:
    UPROPERTY(BlueprintReadWrite, Config, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSoftObjectPath DefaultInfluencerDensityCurve;
    
    FSoftObjectPath DefaultInfluencerSizeCurve;
    UFSDDebrisSettings();
};
