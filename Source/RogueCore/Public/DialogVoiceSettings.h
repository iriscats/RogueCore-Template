#pragma once
#include "CoreMinimal.h"
#include "EDialogVoice.h"
#include "DialogVoiceSettings.generated.h"

USTRUCT(BlueprintType)
struct FDialogVoiceSettings {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EDialogVoice Voice;
    
    float PitchMultiplier;
    ROGUECORE_API FDialogVoiceSettings();
};
