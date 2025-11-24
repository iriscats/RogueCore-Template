#pragma once
#include "CoreMinimal.h"
#include "EFSDSoundParameter.h"
#include "FSDSoundData.generated.h"

class USoundAttenuation;
class USoundBase;
USTRUCT(BlueprintType)
struct FFSDSoundData {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    USoundBase* Sound;
    
    USoundAttenuation* AttenuationOverride;
    EFSDSoundParameter Parameter;
    ROGUECORE_API FFSDSoundData();
};
