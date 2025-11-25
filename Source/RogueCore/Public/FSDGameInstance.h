#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Engine/GameInstance.h"
#include "OnlineSubsystemTypes.h"
#include "OnlineSessionInterface.h"
#include "BXEDroneChangedDelegate.h"
#include "BoscoChangedDelegate.h"
#include "CravityChangedSignatureDelegate.h"
#include "ECharacterSelectorItemStatus.h"
#include "ECharselectionCameraLocation.h"
#include "EMinersManualSection.h"
#include "EOnlineSessionType.h"
#include "ESteamSearchRegion.h"
#include "ESteamServerJoinStatus.h"
#include "FSDServerSearchOptions.h"
#include "ForgingDoneDelegate.h"
#include "GeneratedMissionSignatureDelegate.h"
#include "GenericSignatureDelegate.h"
#include "JoinSignatureDelegate.h"
#include "LoadingScreenInfo.h"
#include "MinersManualNotificationDelegate.h"
#include "NetworkConnectionInfo.h"
#include "NewPostProcessingManagerDelegate.h"
#include "OnGameStateDelegateDelegate.h"
#include "OnGameStateMultiDelegateDelegate.h"
#include "OnHDRGammaChangedDelegate.h"
#include "OnLoaderStartSigDelegate.h"
#include "OnPlayLevelSequenceInCharacterWorldSigDelegate.h"
#include "OnPrivilegeCheckCompleteDelegate.h"
#include "OnXBoxAccountPickerClosedDelegate.h"
#include "OnXBoxChangeUserDelegate.h"
#include "PlayerCharacterSignatureDelegate.h"
#include "ShowCharacterSelectorEqiupSlotSignatureDelegate.h"
#include "ShowCharacterSelectorEquipSignatureDelegate.h"
#include "ShowCharacterSelectorRotateSignatureDelegate.h"
#include "ShowCharacterSelectorSignatureDelegate.h"
#include "ShowCharacterWorldSignatureDelegate.h"
#include "ShowReconnectControllerDelegate.h"
#include "ShowViewer3DSignatureDelegate.h"
#include "SkinSignatureDelegate.h"
#include "StartForgingDelegate.h"
#include "Templates/SubclassOf.h"
#include "TemporaryBuffChangedDelegate.h"
#include "TutorialManagerSignatureDelegate.h"
#include "FSDGameInstance.generated.h"

class AActor;
class ABXECompanionDrone;
class ABosco;
class ACharacterSelectionSwitcher;
class AFSDPlayerController;
class AGameStateBase;
class AMolly;
class APlayerCharacter;
class APlayerController;
class APostProcessingManager;
class AProceduralSetup;
class ATutorialManager;
class UAudioComponent;
class UCampaignManager;
class UDifficultySetting;
class UFSDCloudLoadSave;
class UFSDFriendsAndInvites;
class UFSDGameUserSettings;
class UFSDSaveGame;
class UFSDSendToURL;
class UFXTelemetry;
class UGameData;
class UHUDWarningWidget;
class UIconGenerationManager;
class UItemSkin;
class ULevelSequence;
class UMouseCursorWidget;
class UMutator;
class UObject;
class URunManager;
class USchematic;
class USoundBase;
class USoundSubmix;
class USpecialEvent;
class UStage;
class UStageResultInfo;
class UTemporaryBuff;
class UTexture2D;
class UWindowWidget;
class UWorld;
UCLASS(Blueprintable, NonTransient)
class ROGUECORE_API UFSDGameInstance : public UGameInstance {
    GENERATED_BODY()
    // UPROPERTY fields moved from protected section

public:
    DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FSteamServerJoinStatusDelegate, ESteamServerJoinStatus, status);
    DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FSteamSearchRegionDelegate, ESteamSearchRegion, Region);
    DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnStartSearchForFriendsComplete, bool, bWasSuccessful, const FString&, ErrorStr);
    DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FNewHUDWarningDelegate, UHUDWarningWidget*, newWidget);
    DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FDonkeyCharacterDelegate, AMolly*, InDonkey);
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<UGameData> GameDataClass;
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FTemporaryBuffChanged OnTemporaryBuffAdded;
    FGenericSignature OnGameSettingsChanged;
    FGenericSignature OnGraphicsSettingsChanged;
    FGenericSignature OnPressStart;
    FJoinSignature OnJoinPendingInvite;
    UPROPERTY(BlueprintAssignable, BlueprintCallable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGenericSignature OnSkinChangedEvent;
    FOnLoaderStartSig OnLoaderStart;
    FOnPlayLevelSequenceInCharacterWorldSig OnPlayLevelSequenceInCharacterWorld;
    FGenericSignature OnLoaderStop;
    FShowCharacterWorldSignature OnCharacterSelectionStart;
    FStartForging OnStartForging;
    FStartForging OnSkipForging;
    FForgingDone OnForgingDone;
    FGenericSignature OnCharacterSelectionStop;
    FGenericSignature OnShowCharacterSelectionRefresh;
    FTutorialManagerSignature OnTutorialManagerSet;
    FPlayerCharacterSignature OnLocalPlayerCharacterSet;
    FShowReconnectController OnShowReconnectScreen;
    FOnXBoxAccountPickerClosed OnXBoxAccountPickerClosed;
    FOnXBoxChangeUser OnXBoxChangeUser;
    FOnHDRGammaChanged OnHDRGammaChanged;
    FCravityChangedSignature OnGravityChanged;
    FNewPostProcessingManager OnNewPostProcessingManager;
    UPROPERTY(BlueprintCallable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSkinSignature OnPreviewSkinChanged;
    FOnPrivilegeCheckComplete OnPrivilegeCheckComplete;
    FOnGameStateMultiDelegate OnNewGameState;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    bool ShowingReconnectScreen;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Export, Transient, meta=(AllowPrivateAccess=true))
    TWeakObjectPtr<UMouseCursorWidget> MouseCursorWidget;
    FShowCharacterSelectorSignature OnShowCharacterSelector;
    FShowViewer3DSignature OnShowViewer3D;
    FShowCharacterSelectorEqiupSlotSignature OnShowCharacterSelectorEquipSlot;
    FShowCharacterSelectorEquipSignature OnShowCharacterSelectorEquip;
    FShowCharacterSelectorRotateSignature OnShowCharacterSelectorRotate;
    AProceduralSetup* ProceduralSetup;
    bool HasStartedAMission;
    bool CanPlayOnline;
    bool FirstTimeInFrontend;
    bool SessionFirstStartOnSpaceRig;
    bool ShowFirstCharacterSelector;
    bool ShowSaveWarning;
    AActor* WorldViewTargetDummy;
    UStageResultInfo* MissionResultInfo;
    bool LoaderSequencePlaying;
    AActor* CharacterSelectionLastViewTarget;
    bool HasSeenInfoScreen;
    FTransform CharacterSelectionViewTargetTransform;
    FTransform LoaderViewTargetTransform;
    FGeneratedMissionSignature OnActiveStageChanged;
    FDonkeyCharacterDelegate OnDonkeyChanged;
    TWeakObjectPtr<AMolly> Donkey;
    FBoscoChanged OnBoscoChanged;
    FBXEDroneChanged OnBXEDroneChanged;
    bool DEBUGRandomGlobalMissionSeedEnabled;
    int32 DEBUGRandomGlobalMissionSeed;
    int32 DEBUGFixedGlobalMissionSeed;
    int32 DEBUGFixedPLSSeed;
    bool CanCommunicateOnline;
    FSteamSearchRegionDelegate OnSteamSearchRegionChanged;
    FSteamServerJoinStatusDelegate OnSteamServerJoinStatusChanged;
    FOnStartSearchForFriendsComplete OnStartSearchForFriendsComplete;
    TMap<FString, FString> FriendSessions;
    UFXTelemetry* FXTelemetry;
    USpecialEvent* ForcedMachineEvent;
    USpecialEvent* ForcedOtherEvent;
    bool ShowMinerManualWorkInProgress;
    FMinersManualNotification OnMinersManualNotification;
    FNewHUDWarningDelegate OnNewHUDWarning;
 
    float LastDreadnaughtKillTime;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Export, meta=(AllowPrivateAccess=true))
    TWeakObjectPtr<UWindowWidget> ActiveEscapeMenu;
    TWeakObjectPtr<APostProcessingManager> PostProcessingManager;
    TWeakObjectPtr<ABosco> drone;
    TWeakObjectPtr<ABXECompanionDrone> BXEDrone;
    TWeakObjectPtr<APlayerCharacter> LocalPlayerCharacter;
    TWeakObjectPtr<ATutorialManager> TutorialManager;
    ACharacterSelectionSwitcher* CharacterSelectionSwitcher;
    bool bGameSettingsChanged;
    FFSDServerSearchOptions ServerSearchOptions;
    bool ServerSearchActive;
    FGenericSignature OnHideIdentifiableInformation;
    FGenericSignature OnShowIdentifiableInformation;
    bool IsOnPressStartScreen;
    bool HasSeenStartScreen;
    TSubclassOf<AProceduralSetup> ProceduralLevel;
    TSubclassOf<UIconGenerationManager> IconGenerationManagerClass;
    UIconGenerationManager* IconGenerationManager;
    UCampaignManager* CampaignManager;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, Transient, meta=(AllowPrivateAccess=true))
    URunManager* RunManager;
    UDifficultySetting* DesiredDifficulty;
    UFSDSaveGame* SaveGame;
    TArray<UWorld*> AlwaysLoadedWorlds;
    bool ShowCharacterSelectionWorld;
    TSubclassOf<AActor> Viewer3DClass;
    bool ShowLoaderWorld;
    bool CharacterSelectionWorldActive;
    bool MixerInteractivityEnabled;
    bool LoaderWorldActive;
    bool ResetHUDWhenReturning;
    bool MovieModeActive;
    bool MovieModeActiveInSpacerig;
    bool MovieModeStartAtOrigin;
    bool MovieModeStartWithCameraShake;
    USchematic* ActiveForgeSchematic;
    UFSDCloudLoadSave* FSDCloudLoadSave;
    UFSDSendToURL* SendToURL;
    UFSDFriendsAndInvites* FriendsAndInvites;
    UPROPERTY(EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    double SessionStartTime;
    int32 SessionStartTimestamp;
    float InKBytesPerSecond;
    float OutKBytesPerSecond;
    bool PreSpawnNigaraParticles;
    TArray<UTemporaryBuff*> TemporaryBuffs;
    FLoadingScreenInfo NextLoadingSequence;
    TSoftObjectPtr<ULevelSequence> DeepDiveLoaderSequence;
    TSoftObjectPtr<ULevelSequence> DeepDiveLoaderSequence2;
    USoundSubmix* ControllerVibrationSubmix;
    USoundSubmix* ControllerSpeakerSubmix;
    bool ChatHasFocus;
    FText UncommitedChatMesssage;
    TArray<FNetworkConnectionInfo> ConnectionInfoCahce;
    UAudioComponent* TransitionMusicComponent;
    UFSDGameInstance();
    UFUNCTION(BlueprintCallable)
    void UpdateGlobelMissionSeed();
    void StopPhotographyInputProcessor();
    void StopPersonalAnalytics();
    void StartPhotographyInputProcessor();
    void StartPersonalAnalytics();
    AProceduralSetup* SpawnProcedural();
    void ShowEndScreenLevel();
    void SetViewer3DClass(TSubclassOf<AActor> NewClass, ECharselectionCameraLocation Location);
    void SetSteamServerJoinStatus(ESteamServerJoinStatus NewStatus);
    void SetSteamSearchRegion(ESteamSearchRegion NewRegion);
    void SetServerSearchOptions(const FFSDServerSearchOptions& Options);
    void SetServerSearchActive(bool Active);
    void SetProceduralMap(TSubclassOf<AProceduralSetup> procedural);
    void SetMinersManualNotification(EMinersManualSection Section, UObject* IdentifyingObject, FText Text);
    void SetLoaderWorldVisible(bool V, bool ResetHUD);
    void SetHasSeenInfoScreen();
    void SetGlobalMissionSeed(int32 Seed);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void SetEligableForRetirementAssignment(bool eligable);

    void SetCharacterSelectionWorldVisible(bool V, ECharselectionCameraLocation CameraLocation, bool ResetHUD, ECharacterSelectorItemStatus itemStatus);
    void SetCharacterSelectionSwitcher(ACharacterSelectionSwitcher* switcher);
    void SetBXEDroneInstance(ABXECompanionDrone* NewDrone);
    void SetBoscoInstance(ABosco* NewBosco);
    void SendSteamInfo();
    void ScheduleResetOfWorldsAndGameDataThenOpenLevel(FName LevelName);
    void RestoreCursors();
    void ResetViewer3DClass();
    void ResetSaveGame();
    void ResetAlwaysLoadedWorldsAndGameData();
    void RemoveBXEDrone();
    void RemoveBosco();
    void RemoveAllTemporaryBuff(APlayerController* PlayerController);
    void PreClientTravelCleanup(APlayerController* PlayerController);
    void PostInit(bool reload);
    void PairingUsePreviousProfile();
    void PairingUseNewProfile();
    void OnLoadComplete(const FString& MapName);
    void OnGameStateSet(const AGameStateBase* GameStateBase);
    void OnGameStateChanged(const FOnGameStateDelegate& OnNewStateSet, bool CallInstantlyIfAlreadySet);
    void LoadSaveGame(UFSDSaveGame* toLoad);
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsMutatorActive(TSubclassOf<UMutator> mutatorClass) const;
    bool IsGenericMutatorActive(FName InTag) const;
    bool IsFreeBeerRewardActive() const;
    bool IsCharacterSelectionWorldVisible() const;
    bool IsCampaignMission();
    void HideEndScreenLevel();
    bool HasSignedIn();
    bool HasRandomBeerBuff() const;
    bool HasPendingActivity() const;
    bool HasAnalytics();
    void GraphicsUserSettingsChanged();
    void GiveTemporaryBuff(UTemporaryBuff* buff, APlayerCharacter* Player);
    FVector2D GetViewportSize();
    TSoftClassPtr<AProceduralSetup> GetSoftReferenceToPLS();
    EOnlineSessionType GetSessionType() const;
    TArray<FOnlineSessionSearchResult> GetServersFriendsArePlaying(TArray<FOnlineSessionSearchResult> servers);
    UFUNCTION(BlueprintCallable, BlueprintPure, meta=(WorldContext="WorldContextObject"))
    static FString GetSeedString(UObject* WorldContextObject);
    TArray<UMutator*> GetMutators(TSubclassOf<UMutator> mutatorClass) const;
    AFSDPlayerController* GetLocalFSDPlayerController() const;
    UIconGenerationManager* GetIconGenerationManager() const;
    bool GetHasSeenInfoScreen();
    int32 GetGlobalMissionSeed() const;
    UMutator* GetFirstMutator(TSubclassOf<UMutator> mutatorClass) const;
    TArray<FNetworkConnectionInfo> GetConnectionInfo();
    APlayerCharacter* GetCharacterSelectorCharacter();
    UStage* GetActiveStage() const;
    void GameUserSettingsChanged();
    FText ChatState_UncommitedMessage();
    void ChatState_StoreState(bool focus, const FText& uncommitedMessage);
    bool ChatState_HadFocus();
    void ChangeSkinPreview(UItemSkin* PreviewSkin);
    void CachePSOsOnCommand();
    void BroadcastActiveStageChanged(UStage* NewActiveStage);
    void ApplyGameUserSettings(UFSDGameUserSettings* Settings);
    UHUDWarningWidget* AddWarningToHUD(TSubclassOf<UHUDWarningWidget> WidgetClass, UTexture2D* Texture, USoundBase* PingSound);
    void AddToFriendSessions(const FString& friendSessionId, const FString& friendName);
    void AddStatValue(const FString& Key, float Value);
    void AddStatCount(const FString& Key, int32 count);
};
