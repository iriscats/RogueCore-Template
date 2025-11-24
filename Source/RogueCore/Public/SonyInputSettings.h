#pragma once
#include "CoreMinimal.h"
#include "ESonyControllerLightMode.h"
#include "ESonyControllerMotionMapping.h"
#include "SonyInputSettings.generated.h"

USTRUCT(BlueprintType)
struct FSonyInputSettings {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool MotionControlEnabled;
    
    float MotionControlXSensitivity;
    float MotionControlYSensitivity;
    bool MotionControlPrecisionMode;
    bool MotionControlSalute;
    bool MotionControlFlight;
    ESonyControllerMotionMapping MotionXMapping;
    bool AdaptiveTriggersEnabled;
    float ControllerSpeakerVolume;
    bool ControllerSpeakerMissionControl;
    bool ControllerSpeakerSalute;
    bool ControllerSpeakerFlare;
    bool ControllerSpeakerMineralCollection;
    bool TouchPadTerrainScannerEnabled;
    float TouchPadTerrainScannerXSensitivity;
    float TouchPadTerrainScannerYSensitivity;
    float TouchPadTerrainScannerZoomSensitivity;
    bool TouchPadGesturesEnabled;
    ESonyControllerLightMode ControllerLightMode;
    ROGUECORE_API FSonyInputSettings();
};
