#pragma once
#include "CoreMinimal.h"
#include "UDLSSMode.h"
#include "CharacterOptions.h"
#include "ControllerSettings.h"
#include "CustomKeyBinding.h"
#include "EAbilityActivationMode.h"
#include "EConsoleGraphicsMode.h"
#include "HUDElements.h"
#include "UFSDStreamlineDLSSGMode.h"
#include "ConsoleOptionsInSaveGame.generated.h"

USTRUCT(BlueprintType)
struct FConsoleOptionsInSaveGame {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FControllerSettings ControllerSettings;
    
    FHUDElements HUDElements;
    EAbilityActivationMode AbilityActivationMode;
    bool SaveGameOptionsValid;
    bool bTutorialHintsEnabled;
    bool bShowFPS;
    int32 ShowNetInfoLevel;
    float FOV;
    float HeadbobbingScale;
    float CameraShakeScale;
    float UIDPIScale;
    float volumeCharacterVoice;
    float volumeMaster;
    float volumeMissionControl;
    float volumeSFX;
    float volumeMusic;
    bool bShowSubtitles;
    bool InvertMouse;
    bool PhotosensitiveMode;
    bool bHoldToSprint;
    bool bToggleLaserPointer;
    bool bToggleTerrainScanner;
    bool bUseMouseSmoothing;
    float MouseXSensitivity;
    float MouseYSensitivity;
    bool bUseSeperateSensitivity;
    bool bInvertMouseWheel;
    bool bInvertIncapacitatedX_Mouse;
    bool bInvertIncapacitatedX_Controller;
    bool bInvertFlightControls;
    bool bShowUIAnimations;
    bool bPlaySoundOnChatMessage;
    float ChatFadeTime;
    float ForceFeedbackScale;
    UPROPERTY(BlueprintReadWrite, Config, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 ChatFontSize;
    float HDRColorGamma;
    EConsoleGraphicsMode ConsoleGraphicsMode;
    FString Language;
    FCharacterOptions CharacterOptions;
    TArray<FCustomKeyBinding> CustomKeyBindings;
    TArray<FCustomKeyBinding> CustomControllerBindings;
    bool SwapControllerThumbsticks;
    float FSDResolutionScale;
    int32 UpscalingType;
    int32 AmdFsrMode;
    int32 AmdFsr2Mode;
    UDLSSMode NvidiaDlssMode;
    float AmdFsrSharpness;
    float AmdFsr2Sharpness;
    float NvidiaDlssSharpness;
    UFSDStreamlineDLSSGMode FrameGenerationMode;
    ROGUECORE_API FConsoleOptionsInSaveGame();
};
