#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "GameFramework/Character.h"
#include "UObject/UnrealType.h"
#include "Engine/NetSerialization.h"
#include "GameplayTagContainer.h"
#include "GameplayTags/GameplayTagAssetInterface.h" 
#include "AcceptInviteSignatureDelegate.h"
#include "ActionHoldEventDelegate.h"
#include "AnalogAimSettings.h"
#include "BoolDelegateDelegate.h"
#include "CameraModeChangedDelegate.h"
#include "CameraSpringSettings.h"
#include "CharacterDelegateDelegate.h"
#include "CollectedDrinkDelegateDelegate.h"
#include "CollectedEverythingEventDelegate.h"
#include "CollectedPickaxePartDelegateDelegate.h"
#include "CollectedVanityItemDeledateDelegate.h"
#include "CollectedVictoryPoseEventDelegate.h"
#include "CoolDownProgressStyle.h"
#include "DamagedEnemyEventDelegate.h"
#include "DamagedEnemyServerEventDelegate.h"
#include "DepthSignatureDelegate.h"
#include "DownCameraSettings.h"
#include "DownCameraTargetChangedDelegate.h"
#include "ECharacterCameraMode.h"
#include "ECharacterState.h"
#include "EInputKeys.h"
#include "EnemyStaggeredServerDelegate.h"
#include "EnhancedTrace.h"
#include "HeadlightOnChangedEventDelegate.h"
#include "HeroInfo.h"
#include "HoldButton.h"
#include "IgnoreInviteSignatureDelegate.h"
#include "LaserPointerEventDelegate.h"
#include "OnCallDonkeySignatureDelegate.h"
#include "OnCharacterDeathChangeSignatureDelegate.h"
#include "OnCharacterStateChangedSignatureDelegate.h"
#include "OnFlareThrownDelegate.h"
#include "OnJumpPressedSignatureDelegate.h"
#include "OnJumpReleasedSignatureDelegate.h"
#include "OnLaserPointerPressedSignatureDelegate.h"
#include "OnMinePressedSignatureDelegate.h"
#include "OnPerkActivationTimerFinishedDelegate.h"
#include "OnPlayerShoutEventDelegate.h"
#include "OnRefreshPlayerDataTelemetryDelegate.h"
#include "OpenChatSignatureDelegate.h"
#include "PlatformComponent.h"
#include "PlaySoundInterface.h"
#include "PlayerCharacterEventDelegate.h"
#include "RejectInviteSignatureDelegate.h"
#include "RejoinListener.h"
#include "ReviveCallEventDelegate.h"
#include "SaluteEventDelegate.h"
#include "SchematicEventDelegate.h"
#include "SkinEventDelegate.h"
#include "Targetable.h"
#include "Templates/SubclassOf.h"
#include "TestGenerationPacket.h"
#include "ThrowCarriableDelegateDelegate.h"
#include "ToggleMapToolSignatureDelegate.h"
#include "UpdateMeshesSignatureDelegate.h"
#include "PlayerCharacter.generated.h"

class AActor;
class ADamageEnhancer;
class AFSDPhysicsActor;
class AFSDPlayerController;
class AFSDPlayerState;
class AItem;
class APlayerCharacter;
class APlayerController;
class ARewardDispenserBase;
class AShieldGeneratorActor;
class ATutorialManager;
class AZipLineProjectile;
class UAbilityComponent;
class UAbilityData;
class UAccessCollectionComponent;
class UActorTrackingComponent;
class UAnimMontage;
class UAudioComponent;
class UBXEStatCounterComponent;
class UBoosterDeckContainerComponent;
class UCameraComponent;
class UCappedResource;
class UCharacterCameraController;
class UCharacterIntoxicationComponent;
class UCharacterRecoilComponent;
class UCharacterSightComponent;
class UCharacterStateComponent;
class UCharacterUseComponent;
class UCharacterVanityComponent;
class UCommunicationComponent;
class UCrosshairExtensionComponent;
class UDamageNumberAggregator;
class UDataAsset;
class UElementComponent;
class UElementEventType;
class UElementType;
class UEnemyDescriptor;
class UFSDAchievement;
class UFSDPhysicalMaterial;
class UFSDPlayerCheatComponent;
class UFXSystemAsset;
class UHeightenedSenseComponent;
class UInstantUsable;
class UInventoryComponent;
class UInventoryList;
class UJetBootsMovementComponent;
class ULightComponent;
class UMaterialInstanceDynamic;
class UMaterialInterface;
class UMissionStatsCollector;
class UObject;
class UOutlineComponent;
class UPawnAffliction;
class UPawnStatsComponent;
class UPerkActivationWidget;
class UPerkAsset;
class UPerkComponent;
class UPhysicsAsset;
class UPlayerAfflictionComponent;
class UPlayerAmbienceSoundComponent;
class UPlayerAnimInstance;
class UPlayerAttackPositionComponent;
class UPlayerCharacterID;
class UPlayerEventsComponent;
class UPlayerFPAnimInstance;
class UPlayerHealthComponent;
class UPlayerInfoComponent;
class UPlayerReactiveTerrainTrackerComponent;
class UPlayerTPAnimInstance;
class UPointLightComponent;
class UResourceData;
class USceneComponent;
class USchematic;
class USingleUsableComponent;
class USkeletalMeshComponent;
class USoundAttenuation;
class USoundBase;
class USoundClass;
class USoundConcurrency;
class USoundCue;
class USpringArmComponent;
class UStatusEffect;
class UStatusEffectsComponent;
class UTemporaryBuff;
class UTexture2D;
class UUpgradeContainerComponent;
class UUsableComponent;
class UUseAnimationSetting;
class UWeaponTagBonusesComponent;
class UWidgetInteractionComponent;
class UZipLineStateComponent;
UCLASS(Abstract, Blueprintable, NoExport, Config=Engine)
class ROGUECORE_API APlayerCharacter : public ACharacter, public ITargetable, public IRejoinListener, public IPlaySoundInterface {
    GENERATED_BODY()
    // UPROPERTY fields moved from protected section

public:
    DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FPlayerDelegate, APlayerCharacter*, Player);
    DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnPlayerStateMultiDelegate, AFSDPlayerState*, PlayerState);
    DECLARE_DYNAMIC_DELEGATE_OneParam(FOnPlayerStateDelegate, AFSDPlayerState*, PlayerState);
    DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FKilledGrabber, AActor*, Grabber);
    DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FItemUseDelegate, AItem*, Item);
    DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FInstantReviveDelegate, AActor*, Player, APlayerCharacter*, User);
    DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FGenericAnimNotifyDelegate, APlayerCharacter*, Player);
    DECLARE_DYNAMIC_MULTICAST_DELEGATE(FFirePressedDelegate);
    DECLARE_DYNAMIC_MULTICAST_DELEGATE_ThreeParams(FCoolDownProgressDelegate, UObject*, CoolDownObject, FCoolDownProgressStyle, Style, float, Progress);
    DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FCloseToFlareChanged, APlayerCharacter*, Player, bool, IsCloseToFlare);
    DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FCanEscapeGrabberDelegate, bool, bCanEscape);
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FItemUseDelegate OnStartedUsingItem;
    FItemUseDelegate OnStoppedUsingItem;
    FFirePressedDelegate OnFirePressed;
    FFirePressedDelegate OnFireReleased;
    FOnPlayerStateMultiDelegate OnPlayerStateSet;
    FBoolDelegate OnGrenadePressed;
    FBoolDelegate OnStandingStillChanged;
    FBoolDelegate OnRunningChangedServer;
    FInstantReviveDelegate OnInstantRevivePossibleEvent;
    UPROPERTY(BlueprintAssignable, BlueprintCallable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGenericAnimNotifyDelegate OnGenericAnimNotify;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    USoundCue* AudioDownCameraStatic;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, Transient, meta=(AllowPrivateAccess=true))
    UAudioComponent* AudioComponent_DownCameraStatic;
    UHeightenedSenseComponent* HeightenedSenseComponent;
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, DuplicateTransient, EditAnywhere, meta=(AllowPrivateAccess=true))
    FCollectedEverythingEvent OnCollectedEverything;
    FSchematicEvent OnCollectedSchematic;
    FSkinEvent OnCollectedSkin;
    FCollectedDrinkDelegate OnCollectedDrink;
    FCollectedVictoryPoseEvent OnCollectedVictoryPose;
    FCollectedPickaxePartDelegate OnCollectedPickaxePart;
    FCollectedVanityItemDeledate OnCollectedVanityItem;
    FCameraModeChanged OnCameraModeChanged;
    FDownCameraTargetChanged OnDownCameraTargetChanged;
    FActionHoldEvent OnActionHoldProgress;
    FThrowCarriableDelegate OnThrowCarriableProgress;
    FOnJumpPressedSignature OnJumpPressed;
    FOnJumpReleasedSignature OnJumpReleased;
    FOnMinePressedSignature OnSecondaryFirePressed;
    FOnMinePressedSignature OnSecondaryFireReleased;
    FOnMinePressedSignature OnManualMiningBegin;
    FOnMinePressedSignature OnManualMiningEnd;
    FOnLaserPointerPressedSignature OnLaserPointerPressed;
    FOnLaserPointerPressedSignature OnLaserPointerReleased;
    FOnLaserPointerPressedSignature OnTerrainScannerPressed;
    FOnLaserPointerPressedSignature OnTerrainScannerReleased;
    FOnFlareThrown OnFlareThrown;
    FUpdateMeshesSignature OnUpdateMeshes;
    FOpenChatSignature OnOpenChat;
    FAcceptInviteSignature OnAcceptInvite;
    FRejectInviteSignature OnRejectInvite;
    FIgnoreInviteSignature OnIgnoreInvite;
    FToggleMapToolSignature OnToggleMapTool;
    FDepthSignature OnDepthChanged;
    UPROPERTY(BlueprintAssignable, BlueprintCallable, BlueprintReadWrite, DuplicateTransient, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOnCharacterStateChangedSignature OnCharacterStateChanged;
    FOnCharacterDeathChangeSignature OnCharacterDeathChange;
    FDamagedEnemyEvent OnDamagedEnemy;
    FDamagedEnemyServerEvent OnDamagedEnemyServer;
    FEnemyStaggeredServer OnEnemyStaggered;
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    FLaserPointerEvent OnLaserPointerEvent;
    FLaserPointerEvent OnSecondaryLaserPointerEvent;
    FSaluteEvent OnSaluteEvent;
    FOnPlayerShoutEvent OnPlayerShout;
    FOnPlayerShoutEvent OnBoscoSalute;
    UPROPERTY(BlueprintReadWrite, DuplicateTransient, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOnRefreshPlayerDataTelemetry OnRefreshTelemetry;
    UPROPERTY(BlueprintAssignable, BlueprintAuthorityOnly, BlueprintReadWrite, DuplicateTransient, EditAnywhere, meta=(AllowPrivateAccess=true))
    FCharacterDelegate OnRevivedEvent;
    FReviveCallEvent OnReviveCallEvent;
    FPlayerCharacterEvent OnRevivedOtherCharacter;
    FHeadlightOnChangedEvent OnHeadlightOnChanged;
    FOnCallDonkeySignature OnCallDonkey;
    FGameplayTagContainer GameplayTags;
    TSoftClassPtr<UJetBootsMovementComponent> JetBootsComponentSpawnable;
    UZipLineStateComponent* ZipLineStateComponent;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TArray<TSoftClassPtr<AActor>> EscapableGrabberEnemies;
    FKilledGrabber OnKilledGrabber;
    FOnPerkActivationTimerFinished OnPerkActivationTimerFinished;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UPerkActivationWidget* BoundPerkActivationW;
    float PerkActivationTimer;
protected:
    FCloseToFlareChanged OnCloseToFlareChanged;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, ReplicatedUsing=OnRep_IsCloseToFlare, meta=(AllowPrivateAccess=true))
    bool IsCloseToFlare;
    FCanEscapeGrabberDelegate OnCanEscapeGrabberChanged;
    TSubclassOf<AActor> GrabbedByClass;
    FCoolDownProgressDelegate OnCoolDownProgress;
    bool bIsBeingBittenByCaveLeech;
    UWidgetInteractionComponent* WidgetInteraction;
    UPROPERTY(BlueprintReadWrite, Config, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FPlatformComponent> PlatformComponentClasses;
    FDownCameraSettings DownCameraSettings;
    UPROPERTY(EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TArray<TWeakObjectPtr<AShieldGeneratorActor>> ActiveShieldGenerators;
    FGuid SavegameID;
    FVector EstimatedVelocity;
    FHoldButton FlareHeadlightButton;
    FHoldButton AbilityButton;
    FHoldButton CycleItemButton;
    FHoldButton ToggleHUDButton;
    float EquipLaserpointerHoldDuration;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Replicated, Transient, meta=(AllowPrivateAccess=true))
    bool IsPressingMovementInputKey;
    UPlayerCharacterID* characterID;
    TSoftClassPtr<ATutorialManager> TutorialManagerType;
    TSoftClassPtr<ATutorialManager> TutorialManagerSpacerig;
    USkeletalMeshComponent* FPMesh;
    UCameraComponent* FirstPersonCamera;
    USceneComponent* FirstPersonRoot;
    UActorTrackingComponent* ActorTracking;
    UCharacterIntoxicationComponent* IntoxicationComponent;
    UMissionStatsCollector* MissionStatsCollector;
    USpringArmComponent* ThirdPersonSpringArm;
    UCameraComponent* ThirdPersonCamera;
    UPointLightComponent* ThirdPersonLight;
    USpringArmComponent* FollowSpringArm;
    UDamageNumberAggregator* DamageNumberAggregator;
    UCameraComponent* FollowCamera;
    UCameraComponent* GymCamera;
    UPerkComponent* PerkComponent;
    UFSDPlayerCheatComponent* PlayerCheatComponent;
    USpringArmComponent* GymSpringArm;
    UCameraComponent* DownCamera;
    UCharacterCameraController* CameraController;
    UPlayerHealthComponent* HealthComponent;
    UCharacterSightComponent* SightComponent;
    UInventoryComponent* InventoryComponent;
    UCharacterUseComponent* UseComponentNew;
    USingleUsableComponent* UsableComponent;
    UOutlineComponent* OutlineComponent;
    UCharacterRecoilComponent* RecoilComponent;
    UStatusEffectsComponent* StatusEffectsComponent;
    UPawnStatsComponent* PawnStatsComponent;
    UPlayerAfflictionComponent* PawnAfflictionComponent;
    UPlayerInfoComponent* PlayerInfoComponent;
    UPlayerAttackPositionComponent* AttackerPositioningComponent;
    UCommunicationComponent* CommunicationComponent;
    UElementComponent* ElementComponent;
    UPlayerReactiveTerrainTrackerComponent* ReactiveTerrainTracker;
    UWeaponTagBonusesComponent* WeaponTagBonuses;
    UInstantUsable* TrackGrindUsableComponent;
    UBXEStatCounterComponent* StatCounterComponent;
    UAbilityComponent* AbilityComponent;
    UPlayerAmbienceSoundComponent* PlayerAmbienceSoundComponent;
    UPlayerEventsComponent* PlayerEvents;
    UCrosshairExtensionComponent* CrosshairExtensionComponent;
    UAccessCollectionComponent* AccessCollectionComponent;
    UBoosterDeckContainerComponent* BioBoosterDecksComponent;
    UUpgradeContainerComponent* UpgradeContainerComponent;
    float RunningSpeed;
    float RunBoost;
    TArray<TSubclassOf<UStatusEffect>> RunningBoostEffects;
    float RunBoostChargeTime;
    USoundCue* RunBoostActivationSound;
    UFXSystemAsset* RunBoostParticles;
    UPawnAffliction* RunBoostAffliction;
    UPhysicsAsset* HangingPhysicsAsset;
    float HangingSimulationBlend;
    bool IsPlayableCharacter;
    UAudioComponent* SprintSoundComponent;
    USoundCue* SpringSound;
    FAnalogAimSettings AimSettings;
    float DownedCameraMinPitch;
    float DownedCameraMaxPitch;
    float TurnToFaceScannerAngularSpeed;
    float Turn180Time;
    float CarryingMovementSpeedPenalty;
    float CarryingMaxFallVelocity;
    float MaxThrowProgress;
    float MaxThrowHoldDuration;
    float CarryingThrowMinForce;
    float CarryingThrowMaxForce;
    float PlayerVelocityToThrowFactor;
    TSubclassOf<UStatusEffect> CarryingThrowingStatusEffect;
    float ThrowCarriableProgress;
    TMap<uint8, UCharacterStateComponent*> CharacterStates;
    TWeakObjectPtr<ATutorialManager> TutorialManager;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, Transient, ReplicatedUsing=OnRep_CharacterState, meta=(AllowPrivateAccess=true))
    UCharacterStateComponent* ActiveCharacterState;
    bool IsInDropPod;
    bool IsInEscapePod;
    float ButtonMemoryDuration;
    bool IsRunning;
    bool SprintingEnabled;
    bool CanDash;
    float DashInputWindow;
    float DashFowardMovementMinRequirement;
    float DashRightMovementMaxRequirement;
    float DashControllerMinValueRequired;
    float DashCooldown;
    TSubclassOf<UStatusEffect> DashStatusEffect;
    float StandingStillActivationTime;
    float StandingStillMaxVelocity;
    float ForwardInput;
    float RightInput;
    float ControllerForwardInput;
    float ControllerRightInput;
    float StoppedRunningTime;
    float ShoutPressedTime;
    bool bIsUsingItemPressed;
    bool bIsUsingPressed;
    float UsingDelay;
    bool bIsWorkingout;
    bool IsStandingStill;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, ReplicatedUsing=OnRep_HeadLightOn, meta=(AllowPrivateAccess=true))
    bool HeadLightOn;
    bool isUsing;
    float JumpPressedTime;
    bool CanMove;
    bool CanAim;
    bool CanUseItem;
    bool CanChangeItems;
    bool CanMine;
    bool CanSalute;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, ReplicatedUsing=OnRep_IsStandingDown, meta=(AllowPrivateAccess=true))
    bool IsStandingDown;
    bool InDanceRange;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, ReplicatedUsing=OnRep_IsDancing, meta=(AllowPrivateAccess=true))
    bool IsDancing;
    bool CanUseUsables;
    float DanceStartTime;
    UFSDAchievement* HappyFeetAchievement;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, ReplicatedUsing=OnRep_DanceMove, meta=(AllowPrivateAccess=true))
    int32 DanceMove;
    ECharacterCameraMode CameraMode;
    bool IsInCharacterSelectionWorld;
    bool bShouldSpawnAnimEffects;
    float IdleTime;
    UAnimMontage* FPDrinkSalute;
    UAnimMontage* TPDrinkSalute;
    UAnimMontage* CurrentSaluteMontage;
    TArray<UMaterialInterface*> CachedMaterials;
    bool BlockTrackGrindOnLanded;
    FString SteamClassID;
    UMaterialInstanceDynamic* RadarMaterialInstance;
    int32 RadarMaterialAngleParameterIndex;
    FVector LastUpdateVisibiltyPos;
    FVector SpawnLocation;
    UFSDPhysicalMaterial* FallbackPhysicalMaterial;
    bool ClientReady;
    UCharacterStateComponent* NextCharacterState;
    FPlayerDelegate OnAirJumpUsed;
    bool PlayerIsLeavingInDroppod;
    bool CanInstantRevive;
    UCharacterVanityComponent* CharacterVanity;
    USceneComponent* OnLandedAttachTo;
    FCameraSpringSettings CameraSpringSettings;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, ReplicatedUsing=OnRep_UniqueRunID, meta=(AllowPrivateAccess=true))
    FString UniqueRunID;
    TArray<UPerkAsset*> TrackedActivePerks;
    TArray<bool> TrackedPerksThatShouldUpdate;
    int32 TrackedPerksThatAreUpdating;
    APlayerCharacter(const FObjectInitializer& ObjectInitializer);
    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
    UFUNCTION(BlueprintCallable)
    void UseZipLine(AZipLineProjectile* ZipLine, const FVector& Start, const FVector& End);
    void Unparalyze();
    void TryUseInstantRevive(APlayerCharacter* ReviveTarget);
    bool TryFreezeCharacter(UElementType* ElementType, UElementEventType* ElementEventTrigger);
    void ToggleHUDReleased();
    void ToggleHUDPressed();
    void ToggleHeadLight();
    void ThrowFlareReleased();
    void ThrowFlarePressed();
    void ThrowFlare();
    void StopUsingItem();
    void StartTutorials(bool ResetTutorials);
    void StartPerkActivation(UPerkActivationWidget* PerkActivationWidget, float HoldTime);
    UAudioComponent* SpawnSoundAttached(USoundBase* Sound, USceneComponent* AttachToComponent, float PriorityOverride, FName AttachPointName, FVector Location, FRotator Rotation, TEnumAsByte<EAttachLocation::Type> LocationType, bool bStopWhenAttachedToDestroyed, float VolumeMultiplier, float PitchMultiplier, float StartTime, USoundAttenuation* AttenuationSettings, USoundConcurrency* ConcurrencySettings, USoundClass* soundClassOverride, bool bAutoDestroy, bool SendVibration);
    UAudioComponent* SpawnSoundAtLocation(USoundBase* Sound, FVector Location, FRotator Rotation, float VolumeMultiplier, float PitchMultiplier, float StartTime, USoundAttenuation* AttenuationSettings, USoundConcurrency* ConcurrencySettings, bool bAutoDestroy, bool SendVibration);
    UAudioComponent* SpawnSound2D(USoundBase* Sound, float PriorityOverride, float VolumeMultiplier, float PitchMultiplier, float StartTime, USoundConcurrency* ConcurrencySettings, bool bPersistAcrossLevelTransition, bool bAutoDestroy, bool SendVibration);
    static void ShowSimpleHoldProgress(APlayerController* PlayerController, const FText& InDescription, float InProgress);
    void SetStandingDown(bool standingDown);
    void SetRadarMaterialInstance(UMaterialInstanceDynamic* matInstance);
    void SetPlayerResource(UResourceData* Resource, float amount);
    void SetOutsideShieldGenerator(AShieldGeneratorActor* Shield);
    void SetIsCharacterSelectionModel();
    UFUNCTION(BlueprintCallable, Reliable, Server)
    void SetInstantUsables(bool Value);
    void SetInsideShieldGenerator(AShieldGeneratorActor* Shield);
    UFUNCTION(BlueprintAuthorityOnly, BlueprintCallable)
    void SetInCharacterSelectionWorld();
    void SetHeadLight(bool On);
    void SetFallbackPhysicalMaterial(UFSDPhysicalMaterial* PhysMat);
    void SetCameraMode(ECharacterCameraMode newCameraMode);
    void SetAvailableAirJumps(int32 InAmount);
    void SetAttached(USceneComponent* AttachTo, bool DelayUntilLanded);
    void Server_TriggerDash();
    void Server_TestGenerationDesync();
    void Server_StartSalute(UAnimMontage* startSalute);
    void Server_SpawnEnemies(UEnemyDescriptor* descriptor, int32 count);
    void Server_Shouted();
    void Server_SetUsing(bool characterIsUsing);
    void Server_SetRunning(bool characterIsRunning);
    void Server_SetRunBoostActive(bool IsActive);
    void Server_SetIsThrowingCarriable(bool isThrowing);
    void Server_SetIsPressingMovementInput(bool aIsPushingInput);
    void Server_SetIsJumpPressed(bool InJumpPressed);
    void Server_SetDispenserReward(ARewardDispenserBase* Dispenser, UDataAsset* Reward);
    void Server_SetClientReady();
    void Server_InstantRevive(APlayerCharacter* ReviveTarget, EInputKeys Key);
    void Server_GenerationDesyncDataRecieved(const FTestGenerationPacket& InClientPacket);
    void Server_EscapeFromGrabber();
    void Server_ClearBiomeEffects();
    void Server_CheatRevive();
    void Server_CheatKillAllFriendly();
    void Server_CheatKillAll();
    void Server_CheatJetBoots();
    void Server_CheatGodMode();
    void Server_CheatFlyMode(bool Active);
    void Server_CheatDebugFastMode(bool fast);
    void Server_CheatAddAllResourcesToInventory(float amount);
    void Server_CancelThrowingCarriable();
    void Server_CallDonkey();
    void Server_BiomeEffectsEnabled(bool Enabled);
    void Server_AddToTraceQueue(ADamageEnhancer* Target, FEnhancedTrace Item);
    void Server_AddImpulseToActor(AFSDPhysicsActor* Target, FVector_NetQuantize Impulse, FVector_NetQuantize Location, FVector_NetQuantize AngularImpulse);
    void Server_AddImpulse(const FVector_NetQuantizeNormal& Direction, float Force);
    void Server_ActivateTemporaryBuff(UTemporaryBuff* buff);
    void ReviveProgress(float Progress);
    void RevivePlayer();
    UFUNCTION(BlueprintCallable, NetMulticast, Reliable)
    void RequestChangeInGravityScale(float newGravityScale);
    void RemoveRunningBoostEffects(TArray<TSubclassOf<UStatusEffect>> effects);
    void RemoveRunningBoostEffect(TSubclassOf<UStatusEffect> Effect);
    void RemoveCloseFlare();
    void RejectInvite();
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void ReceiveOnHeadlightOn();
    void ReceiveEscapedFromGrabber();
    void Receive_ShowFieldMedicInstantReviveEffects();
    void QuickUseGeneral(const int32 Index);
    void PrepareForEndScreen();
    void PilotVehicle(AActor* Vehicle);
    void Paralyze(AActor* ParalyzedBy);
    void OpenChat();
    void OnResourceFull(UCappedResource* Resource);
    UFUNCTION()
    void OnRep_UniqueRunID();
    UFUNCTION()
    void OnRep_IsStandingDown();
    UFUNCTION()
    void OnRep_IsDancing();
    UFUNCTION()
    void OnRep_IsCloseToFlare(bool prevCloseToFlare);
    UFUNCTION()
    void OnRep_HeadLightOn();
    UFUNCTION()
    void OnRep_DanceMove();
    UFUNCTION()
    void OnRep_CharacterState(UCharacterStateComponent* oldState);
    void SetPlayerStateChanged(const APlayerCharacter::FOnPlayerStateDelegate& OnNewStateSet, bool CallInstantlyIfAlreadySet);
    void OnItemEquipped(AItem* Item);
    void OnCharacterUsed(APlayerCharacter* User, EInputKeys Key);
    void OnCharacterEndUse();
    void OnCharacterBeginUse(APlayerCharacter* User, EInputKeys Key);
    void OnAbilityDeactivated();
    void MouseWheelUp();
    void MouseWheelDown();
    void JumpRelease();
    void JumpPress();
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsWithinDistance(AActor* Source, float Distance) const;
    bool IsWalking() const;
    bool IsUsingPressed() const;
    bool IsUsingItemPressed() const;
    bool IsSuspended() const;
    bool IsStateActive(ECharacterState State) const;
    bool IsSaluting() const;
    bool IsParalyzed() const;
    bool IsMovementInputPressed();
    bool IsMining() const;
    bool IsLyingDown() const;
    bool IsJumpPressed() const;
    bool IsInState(ECharacterState aState) const;
    bool IsIncapacitated() const;
    bool IsFrozen() const;
    bool IsFirstPerson() const;
    bool IsEquipepdActor(AActor* Actor) const;
    bool IsDown() const;
    bool IsBuried() const;
    bool IsAlive() const;
    void InvalidateTeleport();
    void InstantRevive(APlayerCharacter* ReviveTarget, EInputKeys Key);
    void IgnoreInvite();
    bool HasBeenRevived() const;
    UCharacterUseComponent* GetUseComponent() const;
    UPlayerTPAnimInstance* GetTPAnimInstance() const;
    float GetTimeSinceLastRevival() const;
    ECharacterState GetPreviousState() const;
    AFSDPlayerState* GetPlayerState() const;
    FString GetPlayerName() const;
    UPlayerEventsComponent* GetPlayerEvents() const;
    float GetPlayerDirectionAngle() const;
    AFSDPlayerController* GetPlayerController() const;
    UInventoryList* GetInventoryList() const;
    FText GetHeroSwitchToMessage() const;
    FText GetHeroName() const;
    FHeroInfo GetHeroInfo() const;
    UTexture2D* GetHeroIcon() const;
    FLinearColor GetHeroColor() const;
    UPlayerFPAnimInstance* GetFPAnimInstance() const;
    AItem* GetEquippedItem() const;
    float GetDownTime() const;
    APlayerCharacter* GetDownCameraTarget() const;
    USceneComponent* GetDownCameraRotationPoint();
    USceneComponent* GetDownCameraAttachPoint();
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent, BlueprintPure)
    ULightComponent* GetDebugPointLightComponent() const;
    ECharacterState GetCurrentState() const;
    UCommunicationComponent* GetCommunicationComponent() const;
    float GetClassXP();
    UCharacterVanityComponent* GetCharacterVanity() const;
    UCharacterStateComponent* GetCharacterStateComponent(ECharacterState State) const;
    UBXEStatCounterComponent* GetBXEStatCounterComponent() const;
    UBoosterDeckContainerComponent* GetBoosterDeckContainerComponent() const;
    float GetBeginRevivedProgress() const;
    UUsableComponent* GetBeastMasterUsableComponent() const;
    FString GetAnalyticsClass() const;
    FRotator GetAimRotation() const;
    FVector GetActorGroundLocation() const;
    TArray<AShieldGeneratorActor*> GetActiveShieldGenerators();
    UPlayerAnimInstance* GetActiveAnimInstance() const;
    static UAbilityData* GetAbilityData(APlayerCharacter* InCharacter);
    UAbilityComponent* GetAbilityComponent() const;
    void ForceIsPressingMovementInputKey();
    void ExitVehicle();
    void CycleItemUp();
    void CycleItemReleased();
    void CycleItemPressed();
    void CycleItemDown();
    void ConsumeCycleItemButton();
    UFUNCTION(BlueprintCallable, Client, Reliable)
    void Client_TestGenerationDesync();
    void Client_OpenMinersManual();
    void Client_AddImpulse(const FVector_NetQuantizeNormal& Direction, float Force);
    void Client_ActivateTemporaryBuff(UTemporaryBuff* buff);
    void ChangeState(ECharacterState NewState);
    void ChangeIfDifferentState(ECharacterState NewState);
    bool CanEscapeFromGrabber() const;
    void CallDonkeyReleased();
    void CallDonkeyPressed();
    void BP_OnUpdateMeshes();
    void BP_OnControllerReady();
    void AnnounceSchematicCollected(USchematic* InSchematic);
    UFUNCTION(BlueprintCallable, NetMulticast, Unreliable)
    void All_StartSalute(UAnimMontage* saluteMontage);
    void All_ShowImpactEffects(UFXSystemAsset* Particles, FVector_NetQuantize Location, FVector_NetQuantizeNormal Orientation) const;
    void All_ShowFieldMedicInstantReviveEffects();
    void All_PlayCompletedUseMontage(UUseAnimationSetting* useSetting);
    void All_OnCharacterUsedAirJump(APlayerCharacter* InPlayer);
    void AddRunningBoostEffects(TArray<TSubclassOf<UStatusEffect>> effects);
    void AddRunningBoostEffect(TSubclassOf<UStatusEffect> Effect);
    void AddPlayerResource(UResourceData* Resource, float amount);
    void AddImpulseToActor(AFSDPhysicsActor* Target, FVector_NetQuantize Impulse, FVector_NetQuantize Location, FVector_NetQuantize AngularImpulse);
    void AddImpulseFromVector(const FVector& Vector);
    void AddImpulseFromDirectionAndForce(const FVector& Direction, float Force);
    void AddCloseFlare();
    void AcknowledgeCharacterState(ECharacterState eState);
    void AcceptInvite();
};
