#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "UDLSSMode.h"
#include "UObject/UnrealType.h"
#include "GameFramework/GameUserSettings.h"
#include "BoolConfigChangedDelegate.h"
#include "CharacterOptions.h"
#include "ChatFontSizeChangedDelegate.h"
#include "ColorVisionDeficiencyDelegateDelegate.h"
#include "ColorVisionDeficiencySettings.h"
#include "ControllerSettings.h"
#include "CustomKeyBinding.h"
#include "CustomKeyBindingsChangedDelegate.h"
#include "DelegateDelegate.h"
#include "EAbilityActivationMode.h"
#include "EConsoleGraphicsMode.h"
#include "EFSDInputSource.h"
#include "ENVidiaReflexMode.h"
#include "ESaveSlotChangeProcedure.h"
#include "ESteamSearchRegion.h"
#include "ETurn180Mode.h"
#include "EVolumeType.h"
#include "FloatConfigChangedDelegate.h"
#include "HUDElements.h"
#include "InputSourceChangedSignatureDelegate.h"
#include "Int32ConfigChangedDelegate.h"
#include "LanguageChangedDelegate.h"
#include "StringConfigChangedDelegate.h"
#include "UFSDStreamlineDLSSGMode.h"
#include "FSDGameUserSettings.generated.h"

class APlayerController;
class UFSDGameUserSettings;
class UObject;
class USoundClass;
UCLASS(Blueprintable, Config=Engine)
class UFSDGameUserSettings : public UGameUserSettings {
    GENERATED_BODY()
    
public:
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FDelegate OnSettingsChanged;
    
    FBoolConfigChanged OnUseHoldToRunChanged;
    FFloatConfigChanged OnFOVChanged;
    UPROPERTY(BlueprintAssignable, BlueprintCallable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FLanguageChanged OnLanguageChanged;
    FStringConfigChanged OnGameServerNameChanged;
    FChatFontSizeChanged OnFontSizeChanged;
    FBoolConfigChanged OnJukeboxStreamerModeChanged;
    UPROPERTY(BlueprintReadWrite, Config, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bJukeboxStreamerMode;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    bool bGraphicSettingsChanged;
    FString CurrentUserSetSaveSlotName;
    FBoolConfigChanged OnCanShowBloodChanged;
    TMap<FName, bool> NamedBoolSettings;
    FColorVisionDeficiencyDelegate OnColorVisionDeficiencySettingsChanged;
    FColorVisionDeficiencySettings ColorVisionDeficiency;
    int32 ServerSearchRegion;
    bool ServerSearchPasswordRequired;
    float volumeCharacterVoice;
    float volumeMissionControl;
    float volumeMaster;
    float volumeSFX;
    float volumeMusic;
    FString CurrentAudioOutputDeviceId;
    bool UseDefaultAudioOutputDevice;
    float Sharpening;
    int32 AntiAliasingType;
    bool TemporalAAUpsamplingEnabled;
    float volumeVoice;
    int32 UpscalingType;
    int32 AmdFsrMode;
    int32 AmdFsr2Mode;
    int32 AmdFsr3Mode;
    float AmdFsrSharpness;
    float AmdFsr2Sharpness;
    float AmdFsr3Sharpness;
    bool AmdFsr3FrameInterpolation;
    UDLSSMode NvidiaDlssMode;
    float NvidiaDlssSharpness;
    float FSDResolutionScale;
    ENVidiaReflexMode ReflexMode;
    UFSDStreamlineDLSSGMode FrameGenerationMode;
    EAbilityActivationMode AbilityActivationMode;
    USoundClass* soundClassCharacterVoices;
    USoundClass* soundClassMissionControl;
    USoundClass* soundClassMaster;
    USoundClass* soundClassSFX;
    USoundClass* soundClassUI;
    USoundClass* soundClassMusic;
    USoundClass* soundClassVoice;
    int32 ChatFontSize;
    bool bUseVoiceChat;
    bool bUsePushToTalk;
    FString LocalGameServerName;
    FString LocalGameServerNameFiltered;
    bool AppearOffline;
    bool AutoRefreshServerlist;
    float MouseXSensitivity;
    float MouseYSensitivity;
    bool UseSeperateSensetivity;
    bool InvertMouse;
    bool InvertScroolWheel;
    bool useHoldToRun;
    bool useToggleLaserpointer;
    float FOV;
    float HeadbobbingScale;
    float CameraShakeScale;
    float ChatFadeTime;
    bool useStreamerProgram;
    bool SoundOnChatMessage;
    bool PhotosensitiveMode;
    bool ShowUIAnimations;
    bool UseProfanityFilter;
    float ForceFeedbackScale;
    bool InvertFlightControls;
    bool EnableDx12ByDefault;
    float HDRColorGamma;
    EConsoleGraphicsMode ConsoleGraphicsMode;
    float StaticResoultionScale;
    bool UseManuelGrahpicsMode;
    FHUDElements HUDElements;
    FCharacterOptions CharacterOptions;
 
    float DownedTurnDirection_Controller;
    float DownedTurnDirection_Mouse;
    float UIDPIScale;
    bool EnableCustomUIScale;
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    FInputSourceChangedSignature OnInputSourceChanged;
    bool CheckCursorOutOfBounds;
    FBoolConfigChanged OnEnableTutorialHintsChanged;
    FBoolConfigChanged OnShowFPSChanged;
    FInt32ConfigChanged OnShowNetInfoLevelChanged;
    FBoolConfigChanged OnDx12Enabled;
    FIntPoint ResolutionToBeApplied;
    bool VSyncToBeApplied;
    bool Dx12ToBeApplied;
    TEnumAsByte<EWindowMode::Type> InFullscreenModeToBeApplied;
    bool InFullscreenModeToBeAppliedValid;
    bool VSyncToBeAppliedValid;
    bool Dx12ToBeAppliedValid;
    bool ResolutionToBeAppliedValid;
    bool EscMenuActive;
    bool bShowUpgradeExtraDetails;
    FBoolConfigChanged OnShowUpgradeExtraDetailsChanged;
    FCustomKeyBindingsChanged OnCustomKeyBindingsChanged;
    int32 LastNiagaraShaderVerions;
    bool HasKeyboardBeenConnected;
    EFSDInputSource CurrentInputSource;
    EFSDInputSource RequestedInputSource;
    TArray<FCustomKeyBinding> CustomKeyBindings;
    TArray<FCustomKeyBinding> CustomControllerBindings;
    bool SwapControllerThumbsticks;
    bool bTutorialHintsEnabled;
    bool bShowSubtitles;
    bool bShowFPS;
    int32 ShowNetInfoLevel;
    bool bCanShowBlood;
    bool PreventLatejoinCharacterDuplication;
    bool TranslatorDebugModeEnabled;
    bool CritSoundEnabled;
    bool CritSoundFromDoTsEnable;
    bool DamageNumbersEnabled;
    bool MinionDamageNumbersEnabled;
    float DamageNumberSizeScaling;
    FString PreviousCulture;
    FControllerSettings ControllerSettings;
    TArray<int32> SelectedDifficultyLevels;
    TArray<int32> DifficultyLevelsAddedByDefault;
    UFSDGameUserSettings();
    UFUNCTION(BlueprintCallable)
    void UpdateVolumeSettings(USoundClass* CharacterVoices, USoundClass* MissionControl, USoundClass* Master, USoundClass* Music, USoundClass* SFX, USoundClass* UI, USoundClass* Voice);
    void UpdateForceFeedbackScaleOnController(APlayerController* Controller);
    bool ToggleTranslatorDebugMode();
    bool ToggleShowUpgradeExtraDetails();
    void SetZiplineGunAutoSwitch(bool shouldAutoSwitch);
    void SetVSyncEnabledToBeApplied(bool bEnable);
    void SetVolume(EVolumeType volumeType, float Volume);
    void SetVoiceChatEnabled(bool bEnable);
    void SetUseToggleTerrainScanner(bool useToggleTerrainScanner);
    void SetUseToggleLaserpointer(bool NewUseToggleLaserpointer);
    void SetUseStreamerProgram(bool NewUseStreamerProgram);
    void SetUseSeparateSensitivity(bool newSetting);
    void SetUseProfanityFilter(bool shouldUse);
    void SetUseManualGraphicsMode(bool bEnabled);
    void SetUseHoldToRun(bool NewUseHoldToRun);
    UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContextObject"))
    void SetUseDefaultAudioOutputDevice(UObject* WorldContextObject, bool UseDefault);
    void SetUseCustomUIScale(bool UseCustomScale);
    void SetUpscalingType(int32 Type);
    void SetUIDPIScale(float uiscale);
    void SetTutorialHintsEnabled(bool Enabled);
    void SetTurn180Mode(ETurn180Mode InMode);
    void SetTemporalAAUpscalingEnabled(bool bEnable);
    void SetSwapControllerThumbsticks(bool InSwapThumbsticks);
    void SetSteamSearchRegion(ESteamSearchRegion InRegion);
    void SetStaticResolutionScale(float percentage);
    void SetShowUIAnimations(bool shouldShow);
    void SetShowSubtitles(bool Show);
    void SetShowNetInfoLevel(int32 Level);
    void SetShowFPS(bool visible);
    void SetSharpening(float NewSharpening);
    void SetServerSearchPasswordRequired(bool InPasswordRequired);
    void SetScreenResolutionToBeApplied(FIntPoint Resolution);
    void SetReflexMode(ENVidiaReflexMode NewReflexMode);
    void SetPushToTalk(bool bEnable);
    void SetPreviousItemEnabledOnController(bool InEnabled);
    void SetPreventLatejoinCharacterDuplication(bool prevent);
    void SetPlaySoundOnChatMessage(bool playSoundOnMessage);
    void SetPhotosensitiveMode(bool modeOn);
    void SetNvidiaDlssSharpness(float Sharpness);
    void SetNvidiaDlssMode(UDLSSMode Mode);
    void SetMouseYSensitivity(float newSensitivity);
    void SetMouseXSensitivity(float newSensitivity);
    void SetMinionDamageNumbersEnabled(bool Enabled);
    void SetJukeboxStreamerMode(bool InStreamerMode);
    void SetInvertMouseWheel(bool invertMouseWheel);
    void SetInvertMouse(bool NewInvertMouse);
    void SetInvertFlightControls(bool Invert);
    void SetInputSource(EFSDInputSource NewSource);
    void SetHoldToFire(bool HoldToFire);
    void SetHoldToBreakImmobilization(bool holdToBreak);
    void SetHeadBobbingScale(float NewHeadbobbingScale);
    void SetHDRColorGamma(float Gamma);
    void SetGrapplingHookAutoSwitch(bool shouldAutoSwitch);
    void SetGamma(float gamme);
    void SetGameServerName(const int32 LocalUserNum, const FString& Name);
    void SetFullscreenModeToBeApplied(TEnumAsByte<EWindowMode::Type> InFullscreenMode);
    void SetFrameGenerationMode(UFSDStreamlineDLSSGMode NewMode);
    void SetFOV(float NewFOV);
    void SetForceFeedbackScale(float Scale);
    void SetDx12EnabledToBeApplied(bool bEnable);
    void SetDownCameraTurnDirection(EFSDInputSource InputSource, float InDirection);
    void SetDisableMasterEQ(bool B);
    void SetDifficultySelected(int32 Difficulty, bool IsSelected);
    void SetDebugLocalizerMode(bool bEnable);
    void SetDamageNumbersScaling(float Value);
    void SetDamageNumbersEnabled(bool Value);
    void SetCurrentUserSaveSlotName(UObject* WorldContextObject, const FString& SaveSlotName, ESaveSlotChangeProcedure changeProcedure);
    void SetCritSoundFromDoTsEnabled(bool Enabled);
    void SetCritSoundEnabled(bool Enabled);
    void SetConsoleGraphicsMode(EConsoleGraphicsMode Mode);
    void SetColorVisionDeficiency(EColorVisionDeficiency InType, float InSeverity);
    void SetCheckForOutOfBoundsEnabled(bool Enabled);
    void SetChatFontSize(int32 InFontSize);
    void SetChatFadeTime(float FadeTime);
    void SetChatEnabledOnController(bool InEnabled);
    void SetCanShowBlood(bool bloodAllowed);
    void SetCameraShakeScale(float NewCameraShakeScale);
    void SetAutoRefreshServerlist(bool Value);
    bool SetAudioOutputDevice(UObject* WorldContextObject, const FString& DeviceID);
    bool SetAudioInputDevice(const FString& DeviceName);
    void SetAppearOffline(bool bEnable);
    void SetAntiAliasingType(int32 NewAntiAliasingType);
    void SetAMDFSRSharpness(float Sharpness);
    void SetAMDFSRMode(int32 Mode);
    void SetAMDFSR3Mode(int32 Mode);
    void SetAMDFSR2Sharpness(float Sharpness);
    void SetAMDFSR2Mode(int32 Mode);
    void SetAMDFrameGen(bool Enable);
    void SetAimSensitivity(float NewValue);
    void SetAimOuterAcceleration(float NewValue);
    void SetAimDeadZone(float NewValue);
    void SetAbilityActivationMode(EAbilityActivationMode Mode);
    void ResetGraphicsChanges();
    void ResetControllerSettings();
    void PostInitFSDUserSettings(UObject* WorldContextObject);
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsVoiceChatEnabled() const;
    bool IsUpscalingTypeSupported(int32 Type) const;
    static bool IsNvReflexAvailable();
    bool IsManaulGraphicsModeAvailable();
    bool IsFrameGenerationSupported() const;
    bool IsDx12Enabled();
    bool IsDebugLocalizerModeEnabled() const;
    static bool IsCurrentInputSource(EFSDInputSource InputSource);
    bool IsAMDFrameGenEnabled() const;
    UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContext"))
    void InitializeDifficultySelection(UObject* WorldContext, const TArray<int32> Selection);
    bool HasAudioOutputDeviceChanged(FString& AudioDeviceChangedTo);
    bool GetZiplineGunAutoSwitch() const;
    bool GetVSyncEnabledToBeApplied();
    float GetVolume(EVolumeType volumeType);
    bool GetUseToggleTerrainScanner() const;
    bool GetUseToggleLaserPointer() const;
    bool GetUseStreamerProgram() const;
    bool GetUseSeparateSensitivity() const;
    bool GetUseProfanityFilter() const;
    bool GetUseManualGraphicsMode();
    bool GetUseHoldToRun() const;
    bool GetUseDefaultAudioOutputDevice() const;
    bool GetUseCustomUIScale();
    int32 GetUpscalingType() const;
    float GetUIDPIScale() const;
    bool GetTutorialHintsEnabled() const;
    ETurn180Mode GetTurn180Mode() const;
    bool GetTemporalAAUpscalingEnabled() const;
    TArray<UFSDStreamlineDLSSGMode> GetSupportedFrameGenerationModes() const;
    ESteamSearchRegion GetSteamSearchRegion() const;
    float GetStaticResolutionScale();
    bool GetShowUIAnimations() const;
    bool GetShowSubtitles() const;
    int32 GetShowNetInfoLevel() const;
    bool GetShowFPS() const;
    float GetSharpening() const;
    FIntPoint GetScreenResolutionToBeApplied();
    ENVidiaReflexMode GetReflexMode() const;
    bool GetPushToTalk() const;
    bool GetPreviousItemEnabledOnController() const;
    bool GetPreventLatejoinCharacterDuplication() const;
    bool GetPlaySoundOnChatMessage() const;
    bool GetPhotosensitiveMode() const;
    float GetNvidiaDlssSharpness() const;
    UDLSSMode GetNvidiaDlssMode() const;
    float GetMouseYSensitivity() const;
    float GetMouseXSensitivity() const;
    bool GetMinionDamageNumbersEnabled() const;
    bool GetIsDifficultySelected(int32 Difficulty) const;
    bool GetInvertMouseWheel() const;
    bool GetInvertMouse() const;
    bool GetInvertFlightControls() const;
    static EFSDInputSource GetInputSource();
    bool GetHoldToFire() const;
    bool GetHoldToBreakImmobilization() const;
    float GetHeadBobbingScale() const;
    float GetHDRColorGamma();
    bool GetGrapplingHookAutoSwitch() const;
    float GetGamma() const;
    TEnumAsByte<EWindowMode::Type> GetFullscreenModeToBeApplied();
    static UFSDGameUserSettings* GetFSDGameUserSettings();
    UFSDStreamlineDLSSGMode GetFrameGenerationMode() const;
    float GetFOV() const;
    float GetForceFeedbackScale() const;
    bool GetDx12EnabledToBeApplied();
    float GetDownCameraTurnDirection(EFSDInputSource InputSource) const;
    bool GetDisableMasterEQ();
    float GetDamageNumberSizeScaling() const;
    bool GetDamageNumbersEnabled() const;
    FString GetCurrentUserSaveSlotName();
    EFSDInputSource GetCurrentInputSource();
    UFUNCTION(BlueprintCallable, BlueprintPure, meta=(WorldContext="WorldContextObject"))
    bool GetCurrentAudioOutputDevice(UObject* WorldContextObject, FString& AudioDevice);
    FString GetCurrentAudioInputDeviceName();
    float GetCurrentAudioInputDeviceAmplitude(int32 localUserId);
    bool GetCritSoundFromDoTsEnabled() const;
    bool GetCritSoundEnabled() const;
    EConsoleGraphicsMode GetConsoleGraphicsMode();
    bool GetCheckForOutOfBounds();
    int32 GetChatFontSize() const;
    float GetChatFadeTime() const;
    bool GetChatEnabledOnController() const;
    float GetCameraShakeScale() const;
    bool GetAvaliableAudioOutputDevices(UObject* WorldContextObject, TArray<FString>& AudioDevices);
    bool GetAvaliableAudioInputDevices(TArray<FString>& AudioDevices);
    bool GetAvailableScreenResolutionsForNonPrimaryMonitors(TArray<FIntPoint>& Resolutions);
    bool GetAutoRefreshServerlist() const;
    FString GetAudioOutputDeviceName(UObject* WorldContextObject, const FString& DeviceID);
    bool GetAppearOffline();
    int32 GetAntiAliasingType() const;
    float GetAMDFSRSharpness() const;
    int32 GetAMDFSRMode() const;
    int32 GetAMDFSR3Mode() const;
    float GetAMDFSR2Sharpness() const;
    int32 GetAMDFSR2Mode() const;
    bool GetAMDFrameGenOptionAvailable() const;
    float GetAimSensitivity() const;
    float GetAimOuterAcceleration() const;
    float GetAimDeadZone() const;
    EAbilityActivationMode GetAbilityActivationMode() const;
    FString GameServerNameFiltered() const;
    FString GameServerName() const;
    void FSDSetResolutionScale(float NewScaleNormalized);
    static bool FSDSetCurrentLanguage(UObject* WorldContextObject, const FString& Culture);
    static UFSDGameUserSettings* FSDGameUserSettings();
    bool ConsoleGraphicsModeAvailable(EConsoleGraphicsMode Mode);
    void ClearCustomKeyBindings(bool InGamepadKeys);
    bool CanShowBlood() const;
    void ApplyGraphicsChanges();
    void ApplyConsoleGraphicsMode();
};
