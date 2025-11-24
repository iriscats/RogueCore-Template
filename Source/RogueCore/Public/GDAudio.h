#pragma once
#include "CoreMinimal.h"
#include "Templates/SubclassOf.h"
#include "GDAudio.generated.h"

class AFSDReverbVolume;
class UDynamicReverbComponent;
class USoundAttenuation;
class USoundClass;
USTRUCT(BlueprintType)
struct FGDAudio {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSoftObjectPtr<USoundAttenuation> FirstPersonHitscanAttenuationOverride;
    
    TSubclassOf<AFSDReverbVolume> ReverbActor;
    TSubclassOf<UDynamicReverbComponent> DynamicReverbClass;
    float SmallCaveRadius;
    float MediumCaveRadius;
    float LargeCaveRadius;
    float FirstPersonPriority;
    float ThirdPersonPriority;
    USoundClass* FirstPersonSingleFireSoundClass;
    USoundClass* FirstPersonAutomaticFireSoundClass;
    USoundClass* ThirdPersonSingleFireSoundClass;
    USoundClass* ThirdPersonAutomaticFireSoundClass;
    ROGUECORE_API FGDAudio();
};
