#pragma once
#include "CoreMinimal.h"

#include "GameFramework/Character.h"
#include "UObject/UnrealType.h"
#include "Engine/NetSerialization.h"
#include "GameplayTagContainer.h"
#include "GameplayTagAssetInterface.h" 
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

UCLASS(Abstract, Blueprintable, Config=Engine)
class ROGUECORE_API APlayerCharacter : public ACharacter, public ITargetable, public IRejoinListener, public IPlaySoundInterface {
    GENERATED_BODY()

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

    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    FItemUseDelegate OnStartedUsingItem;

    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    FItemUseDelegate OnStoppedUsingItem;

    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    FFirePressedDelegate OnFirePressed;

    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    FFirePressedDelegate OnFireReleased;

    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    FOnPlayerStateMultiDelegate OnPlayerStateSet;

    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    FBoolDelegate OnGrenadePressed;

    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    FBoolDelegate OnStandingStillChanged;

    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    FBoolDelegate OnRunningChangedServer;

    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    FInstantReviveDelegate OnInstantRevivePossibleEvent;

    UPROPERTY(BlueprintAssignable, BlueprintCallable, BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    FGenericAnimNotifyDelegate OnGenericAnimNotify;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    USoundCue* AudioDownCameraStatic;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, Transient, meta = (AllowPrivateAccess = true))
    UAudioComponent* AudioComponent_DownCameraStatic;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, Transient, meta = (AllowPrivateAccess = true))
    UHeightenedSenseComponent* HeightenedSenseComponent;

    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, DuplicateTransient, EditAnywhere, meta = (AllowPrivateAccess = true))
    FCollectedEverythingEvent OnCollectedEverything;

    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, DuplicateTransient, EditAnywhere, meta = (AllowPrivateAccess = true))
    FSchematicEvent OnCollectedSchematic;

    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, DuplicateTransient, EditAnywhere, meta = (AllowPrivateAccess = true))
    FSkinEvent OnCollectedSkin;

    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, DuplicateTransient, EditAnywhere, meta = (AllowPrivateAccess = true))
    FCollectedDrinkDelegate OnCollectedDrink;

    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, DuplicateTransient, EditAnywhere, meta = (AllowPrivateAccess = true))
    FCollectedVictoryPoseEvent OnCollectedVictoryPose;

    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, DuplicateTransient, EditAnywhere, meta = (AllowPrivateAccess = true))
    FCollectedPickaxePartDelegate OnCollectedPickaxePart;

    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, DuplicateTransient, EditAnywhere, meta = (AllowPrivateAccess = true))
    FCollectedVanityItemDeledate OnCollectedVanityItem;

    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, DuplicateTransient, EditAnywhere, meta = (AllowPrivateAccess = true))
    FCameraModeChanged OnCameraModeChanged;

    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, DuplicateTransient, EditAnywhere, meta = (AllowPrivateAccess = true))
    FDownCameraTargetChanged OnDownCameraTargetChanged;

    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, DuplicateTransient, EditAnywhere, meta = (AllowPrivateAccess = true))
    FActionHoldEvent OnActionHoldProgress;

    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, DuplicateTransient, EditAnywhere, meta = (AllowPrivateAccess = true))
    FThrowCarriableDelegate OnThrowCarriableProgress;

    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, DuplicateTransient, EditAnywhere, meta = (AllowPrivateAccess = true))
    FOnJumpPressedSignature OnJumpPressed;

    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, DuplicateTransient, EditAnywhere, meta = (AllowPrivateAccess = true))
    FOnJumpReleasedSignature OnJumpReleased;

    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, DuplicateTransient, EditAnywhere, meta = (AllowPrivateAccess = true))
    FOnMinePressedSignature OnSecondaryFirePressed;

    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, DuplicateTransient, EditAnywhere, meta = (AllowPrivateAccess = true))
    FOnMinePressedSignature OnSecondaryFireReleased;

    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, DuplicateTransient, EditAnywhere, meta = (AllowPrivateAccess = true))
    FOnMinePressedSignature OnManualMiningBegin;

    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, DuplicateTransient, EditAnywhere, meta = (AllowPrivateAccess = true))
    FOnMinePressedSignature OnManualMiningEnd;

    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, DuplicateTransient, EditAnywhere, meta = (AllowPrivateAccess = true))
    FOnLaserPointerPressedSignature OnLaserPointerPressed;

    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, DuplicateTransient, EditAnywhere, meta = (AllowPrivateAccess = true))
    FOnLaserPointerPressedSignature OnLaserPointerReleased;

    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, DuplicateTransient, EditAnywhere, meta = (AllowPrivateAccess = true))
    FOnLaserPointerPressedSignature OnTerrainScannerPressed;

    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, DuplicateTransient, EditAnywhere, meta = (AllowPrivateAccess = true))
    FOnLaserPointerPressedSignature OnTerrainScannerReleased;

    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, DuplicateTransient, EditAnywhere, meta = (AllowPrivateAccess = true))
    FOnFlareThrown OnFlareThrown;

    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, DuplicateTransient, EditAnywhere, meta = (AllowPrivateAccess = true))
    FUpdateMeshesSignature OnUpdateMeshes;

    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, DuplicateTransient, EditAnywhere, meta = (AllowPrivateAccess = true))
    FOpenChatSignature OnOpenChat;

    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, DuplicateTransient, EditAnywhere, meta = (AllowPrivateAccess = true))
    FAcceptInviteSignature OnAcceptInvite;

    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, DuplicateTransient, EditAnywhere, meta = (AllowPrivateAccess = true))
    FRejectInviteSignature OnRejectInvite;

    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, DuplicateTransient, EditAnywhere, meta = (AllowPrivateAccess = true))
    FIgnoreInviteSignature OnIgnoreInvite;

    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, DuplicateTransient, EditAnywhere, meta = (AllowPrivateAccess = true))
    FToggleMapToolSignature OnToggleMapTool;

    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, DuplicateTransient, EditAnywhere, meta = (AllowPrivateAccess = true))
    FDepthSignature OnDepthChanged;

    UPROPERTY(BlueprintAssignable, BlueprintCallable, BlueprintReadWrite, DuplicateTransient, EditAnywhere, meta = (AllowPrivateAccess = true))
    FOnCharacterStateChangedSignature OnCharacterStateChanged;

    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, DuplicateTransient, EditAnywhere, meta = (AllowPrivateAccess = true))
    FOnCharacterDeathChangeSignature OnCharacterDeathChange;

    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, DuplicateTransient, EditAnywhere, meta = (AllowPrivateAccess = true))
    FDamagedEnemyEvent OnDamagedEnemy;

    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, DuplicateTransient, EditAnywhere, meta = (AllowPrivateAccess = true))
    FDamagedEnemyServerEvent OnDamagedEnemyServer;

    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, DuplicateTransient, EditAnywhere, meta = (AllowPrivateAccess = true))
    FEnemyStaggeredServer OnEnemyStaggered;

    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, Transient, meta = (AllowPrivateAccess = true))
    FLaserPointerEvent OnLaserPointerEvent;

    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, DuplicateTransient, EditAnywhere, meta = (AllowPrivateAccess = true))
    FLaserPointerEvent OnSecondaryLaserPointerEvent;

    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, DuplicateTransient, EditAnywhere, meta = (AllowPrivateAccess = true))
    FSaluteEvent OnSaluteEvent;

    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, DuplicateTransient, EditAnywhere, meta = (AllowPrivateAccess = true))
    FOnPlayerShoutEvent OnPlayerShout;

    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, DuplicateTransient, EditAnywhere, meta = (AllowPrivateAccess = true))
    FOnPlayerShoutEvent OnBoscoSalute;

    UPROPERTY(BlueprintReadWrite, DuplicateTransient, EditAnywhere, meta = (AllowPrivateAccess = true))
    FOnRefreshPlayerDataTelemetry OnRefreshTelemetry;

    UPROPERTY(BlueprintAssignable, BlueprintAuthorityOnly, BlueprintReadWrite, DuplicateTransient, EditAnywhere, meta = (AllowPrivateAccess = true))
    FCharacterDelegate OnRevivedEvent;

    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, DuplicateTransient, EditAnywhere, meta = (AllowPrivateAccess = true))
    FReviveCallEvent OnReviveCallEvent;

    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, DuplicateTransient, EditAnywhere, meta = (AllowPrivateAccess = true))
    FPlayerCharacterEvent OnRevivedOtherCharacter;

    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, DuplicateTransient, EditAnywhere, meta = (AllowPrivateAccess = true))
    FHeadlightOnChangedEvent OnHeadlightOnChanged;

    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, DuplicateTransient, EditAnywhere, meta = (AllowPrivateAccess = true))
    FOnCallDonkeySignature OnCallDonkey;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    FGameplayTagContainer GameplayTags;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    TSoftClassPtr<UJetBootsMovementComponent> JetBootsComponentSpawnable;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, Transient, meta = (AllowPrivateAccess = true))
    UZipLineStateComponent* ZipLineStateComponent;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta = (AllowPrivateAccess = true))
    TArray<TSoftClassPtr<AActor>> EscapableGrabberEnemies;

    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    FKilledGrabber OnKilledGrabber;

    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    FOnPerkActivationTimerFinished OnPerkActivationTimerFinished;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta = (AllowPrivateAccess = true))
    UPerkActivationWidget* BoundPerkActivationW;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    float PerkActivationTimer;


    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    FCloseToFlareChanged OnCloseToFlareChanged;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, ReplicatedUsing = OnRep_IsCloseToFlare, meta = (AllowPrivateAccess = true))
    bool IsCloseToFlare;

    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    FCanEscapeGrabberDelegate OnCanEscapeGrabberChanged;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta = (AllowPrivateAccess = true))
    TSubclassOf<AActor> GrabbedByClass;

    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    FCoolDownProgressDelegate OnCoolDownProgress;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta = (AllowPrivateAccess = true))
    bool bIsBeingBittenByCaveLeech;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta = (AllowPrivateAccess = true))
    UWidgetInteractionComponent* WidgetInteraction;

    UPROPERTY(BlueprintReadWrite, Config, EditAnywhere, meta = (AllowPrivateAccess = true))
    TArray<FPlatformComponent> PlatformComponentClasses;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    FDownCameraSettings DownCameraSettings;

    UPROPERTY(EditAnywhere, Transient, meta = (AllowPrivateAccess = true))
    TArray<TWeakObjectPtr<AShieldGeneratorActor>> ActiveShieldGenerators;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    FGuid SavegameID;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    FVector EstimatedVelocity;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    FHoldButton FlareHeadlightButton;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    FHoldButton AbilityButton;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    FHoldButton CycleItemButton;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    FHoldButton ToggleHUDButton;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    float EquipLaserpointerHoldDuration;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Replicated, Transient, meta = (AllowPrivateAccess = true))
    bool IsPressingMovementInputKey;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    UPlayerCharacterID* characterID;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    TSoftClassPtr<ATutorialManager> TutorialManagerType;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    TSoftClassPtr<ATutorialManager> TutorialManagerSpacerig;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta = (AllowPrivateAccess = true))
    USkeletalMeshComponent* FPMesh;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta = (AllowPrivateAccess = true))
    UCameraComponent* FirstPersonCamera;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta = (AllowPrivateAccess = true))
    USceneComponent* FirstPersonRoot;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta = (AllowPrivateAccess = true))
    UActorTrackingComponent* ActorTracking;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, Transient, meta = (AllowPrivateAccess = true))
    UCharacterIntoxicationComponent* IntoxicationComponent;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta = (AllowPrivateAccess = true))
    UMissionStatsCollector* MissionStatsCollector;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta = (AllowPrivateAccess = true))
    USpringArmComponent* ThirdPersonSpringArm;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta = (AllowPrivateAccess = true))
    UCameraComponent* ThirdPersonCamera;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta = (AllowPrivateAccess = true))
    UPointLightComponent* ThirdPersonLight;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta = (AllowPrivateAccess = true))
    USpringArmComponent* FollowSpringArm;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta = (AllowPrivateAccess = true))
    UDamageNumberAggregator* DamageNumberAggregator;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta = (AllowPrivateAccess = true))
    UCameraComponent* FollowCamera;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta = (AllowPrivateAccess = true))
    UCameraComponent* GymCamera;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta = (AllowPrivateAccess = true))
    UPerkComponent* PerkComponent;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta = (AllowPrivateAccess = true))
    UFSDPlayerCheatComponent* PlayerCheatComponent;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta = (AllowPrivateAccess = true))
    USpringArmComponent* GymSpringArm;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta = (AllowPrivateAccess = true))
    UCameraComponent* DownCamera;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta = (AllowPrivateAccess = true))
    UCharacterCameraController* CameraController;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta = (AllowPrivateAccess = true))
    UPlayerHealthComponent* HealthComponent;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta = (AllowPrivateAccess = true))
    UCharacterSightComponent* SightComponent;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta = (AllowPrivateAccess = true))
    UInventoryComponent* InventoryComponent;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta = (AllowPrivateAccess = true))
    UCharacterUseComponent* UseComponentNew;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta = (AllowPrivateAccess = true))
    USingleUsableComponent* UsableComponent;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta = (AllowPrivateAccess = true))
    UOutlineComponent* OutlineComponent;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta = (AllowPrivateAccess = true))
    UCharacterRecoilComponent* RecoilComponent;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta = (AllowPrivateAccess = true))
    UStatusEffectsComponent* StatusEffectsComponent;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta = (AllowPrivateAccess = true))
    UPawnStatsComponent* PawnStatsComponent;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta = (AllowPrivateAccess = true))
    UPlayerAfflictionComponent* PawnAfflictionComponent;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta = (AllowPrivateAccess = true))
    UPlayerInfoComponent* PlayerInfoComponent;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta = (AllowPrivateAccess = true))
    UPlayerAttackPositionComponent* AttackerPositioningComponent;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta = (AllowPrivateAccess = true))
    UCommunicationComponent* CommunicationComponent;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta = (AllowPrivateAccess = true))
    UElementComponent* ElementComponent;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta = (AllowPrivateAccess = true))
    UPlayerReactiveTerrainTrackerComponent* ReactiveTerrainTracker;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta = (AllowPrivateAccess = true))
    UWeaponTagBonusesComponent* WeaponTagBonuses;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta = (AllowPrivateAccess = true))
    UInstantUsable* TrackGrindUsableComponent;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta = (AllowPrivateAccess = true))
    UBXEStatCounterComponent* StatCounterComponent;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, Transient, meta = (AllowPrivateAccess = true))
    UAbilityComponent* AbilityComponent;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta = (AllowPrivateAccess = true))
    UPlayerAmbienceSoundComponent* PlayerAmbienceSoundComponent;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta = (AllowPrivateAccess = true))
    UPlayerEventsComponent* PlayerEvents;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta = (AllowPrivateAccess = true))
    UCrosshairExtensionComponent* CrosshairExtensionComponent;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta = (AllowPrivateAccess = true))
    UAccessCollectionComponent* AccessCollectionComponent;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta = (AllowPrivateAccess = true))
    UBoosterDeckContainerComponent* BioBoosterDecksComponent;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta = (AllowPrivateAccess = true))
    UUpgradeContainerComponent* UpgradeContainerComponent;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    float RunningSpeed;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    float RunBoost;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta = (AllowPrivateAccess = true))
    TArray<TSubclassOf<UStatusEffect>> RunningBoostEffects;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    float RunBoostChargeTime;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    USoundCue* RunBoostActivationSound;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    UFXSystemAsset* RunBoostParticles;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    UPawnAffliction* RunBoostAffliction;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    UPhysicsAsset* HangingPhysicsAsset;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    float HangingSimulationBlend;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    bool IsPlayableCharacter;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, Transient, meta = (AllowPrivateAccess = true))
    UAudioComponent* SprintSoundComponent;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    USoundCue* SpringSound;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    FAnalogAimSettings AimSettings;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    float DownedCameraMinPitch;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    float DownedCameraMaxPitch;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    float TurnToFaceScannerAngularSpeed;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    float Turn180Time;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    float CarryingMovementSpeedPenalty;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    float CarryingMaxFallVelocity;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    float MaxThrowProgress;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    float MaxThrowHoldDuration;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    float CarryingThrowMinForce;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    float CarryingThrowMaxForce;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    float PlayerVelocityToThrowFactor;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    TSubclassOf<UStatusEffect> CarryingThrowingStatusEffect;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta = (AllowPrivateAccess = true))
    float ThrowCarriableProgress;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, Transient, meta = (AllowPrivateAccess = true))
    TMap<uint8, UCharacterStateComponent*> CharacterStates;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta = (AllowPrivateAccess = true))
    TWeakObjectPtr<ATutorialManager> TutorialManager;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, Transient, ReplicatedUsing = OnRep_CharacterState, meta = (AllowPrivateAccess = true))
    UCharacterStateComponent* ActiveCharacterState;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta = (AllowPrivateAccess = true))
    bool IsInDropPod;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta = (AllowPrivateAccess = true))
    bool IsInEscapePod;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    float ButtonMemoryDuration;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Replicated, Transient, meta = (AllowPrivateAccess = true))
    bool IsRunning;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta = (AllowPrivateAccess = true))
    bool SprintingEnabled;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    bool CanDash;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    float DashInputWindow;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    float DashFowardMovementMinRequirement;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    float DashRightMovementMaxRequirement;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    float DashControllerMinValueRequired;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta = (AllowPrivateAccess = true))
    float DashCooldown;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    TSubclassOf<UStatusEffect> DashStatusEffect;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    float StandingStillActivationTime;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    float StandingStillMaxVelocity;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta = (AllowPrivateAccess = true))
    float ForwardInput;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta = (AllowPrivateAccess = true))
    float RightInput;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta = (AllowPrivateAccess = true))
    float ControllerForwardInput;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta = (AllowPrivateAccess = true))
    float ControllerRightInput;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta = (AllowPrivateAccess = true))
    float StoppedRunningTime;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta = (AllowPrivateAccess = true))
    float ShoutPressedTime;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta = (AllowPrivateAccess = true))
    bool bIsUsingItemPressed;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta = (AllowPrivateAccess = true))
    bool bIsUsingPressed;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta = (AllowPrivateAccess = true))
    float UsingDelay;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Replicated, Transient, meta = (AllowPrivateAccess = true))
    bool bIsWorkingout;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta = (AllowPrivateAccess = true))
    bool IsStandingStill;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, ReplicatedUsing = OnRep_HeadLightOn, meta = (AllowPrivateAccess = true))
    bool HeadLightOn;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Replicated, Transient, meta = (AllowPrivateAccess = true))
    bool isUsing;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta = (AllowPrivateAccess = true))
    float JumpPressedTime;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta = (AllowPrivateAccess = true))
    bool CanMove;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta = (AllowPrivateAccess = true))
    bool CanAim;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta = (AllowPrivateAccess = true))
    bool CanUseItem;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta = (AllowPrivateAccess = true))
    bool CanChangeItems;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta = (AllowPrivateAccess = true))
    bool CanMine;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta = (AllowPrivateAccess = true))
    bool CanSalute;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, ReplicatedUsing = OnRep_IsStandingDown, meta = (AllowPrivateAccess = true))
    bool IsStandingDown;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta = (AllowPrivateAccess = true))
    bool InDanceRange;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, ReplicatedUsing = OnRep_IsDancing, meta = (AllowPrivateAccess = true))
    bool IsDancing;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta = (AllowPrivateAccess = true))
    bool CanUseUsables;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta = (AllowPrivateAccess = true))
    float DanceStartTime;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    UFSDAchievement* HappyFeetAchievement;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, ReplicatedUsing = OnRep_DanceMove, meta = (AllowPrivateAccess = true))
    int32 DanceMove;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta = (AllowPrivateAccess = true))
    ECharacterCameraMode CameraMode;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta = (AllowPrivateAccess = true))
    bool IsInCharacterSelectionWorld;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta = (AllowPrivateAccess = true))
    bool bShouldSpawnAnimEffects;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta = (AllowPrivateAccess = true))
    float IdleTime;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    UAnimMontage* FPDrinkSalute;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    UAnimMontage* TPDrinkSalute;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta = (AllowPrivateAccess = true))
    UAnimMontage* CurrentSaluteMontage;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta = (AllowPrivateAccess = true))
    TArray<UMaterialInterface*> CachedMaterials;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta = (AllowPrivateAccess = true))
    bool BlockTrackGrindOnLanded;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    FString SteamClassID;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta = (AllowPrivateAccess = true))
    UMaterialInstanceDynamic* RadarMaterialInstance;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta = (AllowPrivateAccess = true))
    int32 RadarMaterialAngleParameterIndex;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta = (AllowPrivateAccess = true))
    FVector LastUpdateVisibiltyPos;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta = (AllowPrivateAccess = true))
    FVector SpawnLocation;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta = (AllowPrivateAccess = true))
    UFSDPhysicalMaterial* FallbackPhysicalMaterial;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta = (AllowPrivateAccess = true))
    bool ClientReady;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, Transient, meta = (AllowPrivateAccess = true))
    UCharacterStateComponent* NextCharacterState;

    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    FPlayerDelegate OnAirJumpUsed;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Replicated, Transient, meta = (AllowPrivateAccess = true))
    bool PlayerIsLeavingInDroppod;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta = (AllowPrivateAccess = true))
    bool CanInstantRevive;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta = (AllowPrivateAccess = true))
    UCharacterVanityComponent* CharacterVanity;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, Transient, meta = (AllowPrivateAccess = true))
    USceneComponent* OnLandedAttachTo;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    FCameraSpringSettings CameraSpringSettings;

public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, ReplicatedUsing = OnRep_UniqueRunID, meta = (AllowPrivateAccess = true))
    FString UniqueRunID;


    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta = (AllowPrivateAccess = true))
    TArray<UPerkAsset*> TrackedActivePerks;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta = (AllowPrivateAccess = true))
    TArray<bool> TrackedPerksThatShouldUpdate;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta = (AllowPrivateAccess = true))
    int32 TrackedPerksThatAreUpdating;

public:
    APlayerCharacter(const FObjectInitializer& ObjectInitializer);

    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;

    UFUNCTION(BlueprintCallable)
    void UseZipLine(AZipLineProjectile* ZipLine, const FVector& Start, const FVector& End);

    UFUNCTION(BlueprintCallable)
    void Unparalyze();

    UFUNCTION(BlueprintCallable)
    void TryUseInstantRevive(APlayerCharacter* ReviveTarget);

    UFUNCTION(BlueprintCallable)
    bool TryFreezeCharacter(UElementType* ElementType, UElementEventType* ElementEventTrigger);


    UFUNCTION(BlueprintCallable)
    void ToggleHUDReleased();

    UFUNCTION(BlueprintCallable)
    void ToggleHUDPressed();

public:
    UFUNCTION(BlueprintCallable)
    void ToggleHeadLight();


    UFUNCTION(BlueprintCallable)
    void ThrowFlareReleased();

    UFUNCTION(BlueprintCallable)
    void ThrowFlarePressed();

public:
    UFUNCTION(BlueprintCallable)
    void ThrowFlare();


    UFUNCTION(BlueprintCallable)
    void StopUsingItem();

public:
    UFUNCTION(BlueprintCallable)
    void StartTutorials(bool ResetTutorials);

    UFUNCTION(BlueprintCallable)
    void StartPerkActivation(UPerkActivationWidget* PerkActivationWidget, float HoldTime);

    UFUNCTION(BlueprintCallable)
    UAudioComponent* SpawnSoundAttached(USoundBase* Sound, USceneComponent* AttachToComponent, float PriorityOverride, FName AttachPointName, FVector Location, FRotator Rotation, TEnumAsByte<EAttachLocation::Type> LocationType, bool bStopWhenAttachedToDestroyed, float VolumeMultiplier, float PitchMultiplier, float StartTime, USoundAttenuation* AttenuationSettings, USoundConcurrency* ConcurrencySettings, USoundClass* soundClassOverride, bool bAutoDestroy, bool SendVibration);

    UFUNCTION(BlueprintCallable)
    UAudioComponent* SpawnSoundAtLocation(USoundBase* Sound, FVector Location, FRotator Rotation, float VolumeMultiplier, float PitchMultiplier, float StartTime, USoundAttenuation* AttenuationSettings, USoundConcurrency* ConcurrencySettings, bool bAutoDestroy, bool SendVibration);

    UFUNCTION(BlueprintCallable)
    UAudioComponent* SpawnSound2D(USoundBase* Sound, float PriorityOverride, float VolumeMultiplier, float PitchMultiplier, float StartTime, USoundConcurrency* ConcurrencySettings, bool bPersistAcrossLevelTransition, bool bAutoDestroy, bool SendVibration);


    UFUNCTION(BlueprintCallable)
    static void ShowSimpleHoldProgress(APlayerController* PlayerController, const FText& InDescription, float InProgress);

public:
    UFUNCTION(BlueprintCallable)
    void SetStandingDown(bool standingDown);

    UFUNCTION(BlueprintCallable)
    void SetRadarMaterialInstance(UMaterialInstanceDynamic* matInstance);

    UFUNCTION(BlueprintCallable)
    void SetPlayerResource(UResourceData* Resource, float amount);

    UFUNCTION(BlueprintCallable)
    void SetOutsideShieldGenerator(AShieldGeneratorActor* Shield);

    UFUNCTION(BlueprintCallable)
    void SetIsCharacterSelectionModel();

    UFUNCTION(BlueprintCallable, Reliable, Server)
    void SetInstantUsables(bool Value);

    UFUNCTION(BlueprintCallable)
    void SetInsideShieldGenerator(AShieldGeneratorActor* Shield);

    UFUNCTION(BlueprintAuthorityOnly, BlueprintCallable)
    void SetInCharacterSelectionWorld();

    UFUNCTION(BlueprintCallable, Reliable, Server)
    void SetHeadLight(bool On);

    UFUNCTION(BlueprintCallable)
    void SetFallbackPhysicalMaterial(UFSDPhysicalMaterial* PhysMat);

    UFUNCTION(BlueprintCallable)
    void SetCameraMode(ECharacterCameraMode newCameraMode);

    UFUNCTION(BlueprintCallable)
    void SetAvailableAirJumps(int32 InAmount);

    UFUNCTION(BlueprintCallable)
    void SetAttached(USceneComponent* AttachTo, bool DelayUntilLanded);


    UFUNCTION(BlueprintCallable, Reliable, Server)
    void Server_TriggerDash();

public:
    UFUNCTION(BlueprintCallable, Reliable, Server)
    void Server_TestGenerationDesync();


    UFUNCTION(BlueprintCallable, Reliable, Server)
    void Server_StartSalute(UAnimMontage* startSalute);

public:
    UFUNCTION(BlueprintCallable, Reliable, Server)
    void Server_SpawnEnemies(UEnemyDescriptor* descriptor, int32 count);

    UFUNCTION(BlueprintCallable, Reliable, Server)
    void Server_Shouted();


    UFUNCTION(BlueprintCallable, Reliable, Server)
    void Server_SetUsing(bool characterIsUsing);

    UFUNCTION(BlueprintCallable, Reliable, Server)
    void Server_SetRunning(bool characterIsRunning);

    UFUNCTION(BlueprintCallable, Reliable, Server)
    void Server_SetRunBoostActive(bool IsActive);

    UFUNCTION(BlueprintCallable, Reliable, Server)
    void Server_SetIsThrowingCarriable(bool isThrowing);

public:
    UFUNCTION(BlueprintCallable, Reliable, Server)
    void Server_SetIsPressingMovementInput(bool aIsPushingInput);


    UFUNCTION(BlueprintCallable, Reliable, Server)
    void Server_SetIsJumpPressed(bool InJumpPressed);

public:
    UFUNCTION(BlueprintCallable, Reliable, Server)
    void Server_SetDispenserReward(ARewardDispenserBase* Dispenser, UDataAsset* Reward);


    UFUNCTION(BlueprintCallable, Reliable, Server)
    void Server_SetClientReady();

public:
    UFUNCTION(BlueprintCallable, Reliable, Server)
    void Server_InstantRevive(APlayerCharacter* ReviveTarget, EInputKeys Key);

    UFUNCTION(BlueprintCallable, Reliable, Server)
    void Server_GenerationDesyncDataRecieved(const FTestGenerationPacket& InClientPacket);


    UFUNCTION(BlueprintCallable, Reliable, Server)
    void Server_EscapeFromGrabber();

public:
    UFUNCTION(BlueprintCallable, Reliable, Server)
    void Server_ClearBiomeEffects();

    UFUNCTION(BlueprintCallable, Reliable, Server)
    void Server_CheatRevive();

    UFUNCTION(BlueprintCallable, Reliable, Server)
    void Server_CheatKillAllFriendly();

    UFUNCTION(BlueprintCallable, Reliable, Server)
    void Server_CheatKillAll();

    UFUNCTION(BlueprintCallable, Reliable, Server)
    void Server_CheatJetBoots();

    UFUNCTION(BlueprintCallable, Reliable, Server)
    void Server_CheatGodMode();

    UFUNCTION(BlueprintCallable, Reliable, Server)
    void Server_CheatFlyMode(bool Active);

    UFUNCTION(BlueprintCallable, Reliable, Server)
    void Server_CheatDebugFastMode(bool fast);

    UFUNCTION(BlueprintCallable, Reliable, Server)
    void Server_CheatAddAllResourcesToInventory(float amount);


    UFUNCTION(BlueprintCallable, Reliable, Server)
    void Server_CancelThrowingCarriable();

    UFUNCTION(BlueprintCallable, Reliable, Server)
    void Server_CallDonkey();

public:
    UFUNCTION(BlueprintCallable, Reliable, Server)
    void Server_BiomeEffectsEnabled(bool Enabled);

    UFUNCTION(BlueprintCallable, Reliable, Server)
    void Server_AddToTraceQueue(ADamageEnhancer* Target, FEnhancedTrace Item);

    UFUNCTION(BlueprintCallable, Reliable, Server)
    void Server_AddImpulseToActor(AFSDPhysicsActor* Target, FVector_NetQuantize Impulse, FVector_NetQuantize Location, FVector_NetQuantize AngularImpulse);

    UFUNCTION(BlueprintCallable, Reliable, Server)
    void Server_AddImpulse(const FVector_NetQuantizeNormal& Direction, float Force);

    UFUNCTION(BlueprintCallable, Reliable, Server)
    void Server_ActivateTemporaryBuff(UTemporaryBuff* buff);

    UFUNCTION(BlueprintCallable)
    void ReviveProgress(float Progress);

    UFUNCTION(BlueprintCallable)
    void RevivePlayer();

    UFUNCTION(BlueprintCallable, NetMulticast, Reliable)
    void RequestChangeInGravityScale(float newGravityScale);

    UFUNCTION(BlueprintCallable)
    void RemoveRunningBoostEffects(TArray<TSubclassOf<UStatusEffect>> effects);

    UFUNCTION(BlueprintCallable)
    void RemoveRunningBoostEffect(TSubclassOf<UStatusEffect> Effect);

    UFUNCTION(BlueprintAuthorityOnly, BlueprintCallable)
    void RemoveCloseFlare();


    UFUNCTION(BlueprintCallable)
    void RejectInvite();

    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void ReceiveOnHeadlightOn();

    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void ReceiveEscapedFromGrabber();

public:
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void Receive_ShowFieldMedicInstantReviveEffects();


    UFUNCTION(BlueprintCallable)
    void QuickUseGeneral(const int32 Index);

public:
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void PrepareForEndScreen();

    UFUNCTION(BlueprintAuthorityOnly, BlueprintCallable)
    void PilotVehicle(AActor* Vehicle);

    UFUNCTION(BlueprintCallable)
    void Paralyze(AActor* ParalyzedBy);


    UFUNCTION(BlueprintCallable)
    void OpenChat();

    UFUNCTION(BlueprintCallable)
    void OnResourceFull(UCappedResource* Resource);


    UFUNCTION(BlueprintCallable)
    void OnRep_UniqueRunID();


    UFUNCTION(BlueprintCallable)
    void OnRep_IsStandingDown();

    UFUNCTION(BlueprintCallable)
    void OnRep_IsDancing();

    UFUNCTION(BlueprintCallable)
    void OnRep_IsCloseToFlare(bool prevCloseToFlare);

    UFUNCTION(BlueprintCallable)
    void OnRep_HeadLightOn();

    UFUNCTION(BlueprintCallable)
    void OnRep_DanceMove();

    UFUNCTION(BlueprintCallable)
    void OnRep_CharacterState(UCharacterStateComponent* oldState);

public:
    UFUNCTION(BlueprintCallable)
    void OnPlayerStateChanged(const APlayerCharacter::FOnPlayerStateDelegate& OnNewStateSet, bool CallInstantlyIfAlreadySet);


    UFUNCTION(BlueprintCallable)
    void OnItemEquipped(AItem* Item);

    UFUNCTION(BlueprintCallable)
    void OnCharacterUsed(APlayerCharacter* User, EInputKeys Key);

    UFUNCTION(BlueprintCallable)
    void OnCharacterEndUse();

    UFUNCTION(BlueprintCallable)
    void OnCharacterBeginUse(APlayerCharacter* User, EInputKeys Key);

    UFUNCTION(BlueprintCallable)
    void OnAbilityDeactivated();

    UFUNCTION(BlueprintCallable)
    void MouseWheelUp();

    UFUNCTION(BlueprintCallable)
    void MouseWheelDown();

    UFUNCTION(BlueprintCallable)
    void JumpRelease();

    UFUNCTION(BlueprintCallable)
    void JumpPress();

public:
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsWithinDistance(AActor* Source, float Distance) const;

    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsWalking() const;

    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsUsingPressed() const;

    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsUsingItemPressed() const;

    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsSuspended() const;


    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsStateActive(ECharacterState State) const;

public:
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsSaluting() const;

    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsParalyzed() const;

    UFUNCTION(BlueprintCallable)
    bool IsMovementInputPressed();

    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsMining() const;

    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsLyingDown() const;

    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsJumpPressed() const;

    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsInState(ECharacterState aState) const;

    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsIncapacitated() const;

    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsFrozen() const;

    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsFirstPerson() const;

    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsEquipepdActor(AActor* Actor) const;

    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsDown() const;

    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsBuried() const;

    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsAlive() const;


    UFUNCTION(BlueprintCallable, Reliable, Server)
    void InvalidateTeleport();

public:
    UFUNCTION(BlueprintCallable)
    void InstantRevive(APlayerCharacter* ReviveTarget, EInputKeys Key);


    UFUNCTION(BlueprintCallable)
    void IgnoreInvite();

public:
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool HasBeenRevived() const;

    UFUNCTION(BlueprintCallable, BlueprintPure)
    UCharacterUseComponent* GetUseComponent() const;

    UFUNCTION(BlueprintCallable, BlueprintPure)
    UPlayerTPAnimInstance* GetTPAnimInstance() const;

    UFUNCTION(BlueprintCallable, BlueprintPure)
    float GetTimeSinceLastRevival() const;

    UFUNCTION(BlueprintCallable, BlueprintPure)
    ECharacterState GetPreviousState() const;

    UFUNCTION(BlueprintCallable, BlueprintPure)
    AFSDPlayerState* GetPlayerState() const;

    UFUNCTION(BlueprintCallable, BlueprintPure)
    FString GetPlayerName() const;

    UFUNCTION(BlueprintCallable, BlueprintPure)
    UPlayerEventsComponent* GetPlayerEvents() const;

    UFUNCTION(BlueprintCallable, BlueprintPure)
    float GetPlayerDirectionAngle() const;

    UFUNCTION(BlueprintCallable, BlueprintPure)
    AFSDPlayerController* GetPlayerController() const;

    UFUNCTION(BlueprintCallable, BlueprintPure)
    UInventoryList* GetInventoryList() const;

    UFUNCTION(BlueprintCallable, BlueprintPure)
    FText GetHeroSwitchToMessage() const;

    UFUNCTION(BlueprintCallable, BlueprintPure)
    FText GetHeroName() const;

    UFUNCTION(BlueprintCallable, BlueprintPure)
    FHeroInfo GetHeroInfo() const;

    UFUNCTION(BlueprintCallable, BlueprintPure)
    UTexture2D* GetHeroIcon() const;

    UFUNCTION(BlueprintCallable, BlueprintPure)
    FLinearColor GetHeroColor() const;

    UFUNCTION(BlueprintCallable, BlueprintPure)
    UPlayerFPAnimInstance* GetFPAnimInstance() const;

    UFUNCTION(BlueprintCallable, BlueprintPure)
    AItem* GetEquippedItem() const;

    UFUNCTION(BlueprintCallable, BlueprintPure)
    float GetDownTime() const;

    UFUNCTION(BlueprintCallable, BlueprintPure)
    APlayerCharacter* GetDownCameraTarget() const;

    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    USceneComponent* GetDownCameraRotationPoint();

    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    USceneComponent* GetDownCameraAttachPoint();

    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent, BlueprintPure)
    ULightComponent* GetDebugPointLightComponent() const;

    UFUNCTION(BlueprintCallable, BlueprintPure)
    ECharacterState GetCurrentState() const;

    UFUNCTION(BlueprintCallable, BlueprintPure)
    UCommunicationComponent* GetCommunicationComponent() const;

    UFUNCTION(BlueprintCallable, BlueprintPure)
    float GetClassXP();

    UFUNCTION(BlueprintCallable, BlueprintPure)
    UCharacterVanityComponent* GetCharacterVanity() const;

    UFUNCTION(BlueprintCallable, BlueprintPure)
    UCharacterStateComponent* GetCharacterStateComponent(ECharacterState State) const;

    UFUNCTION(BlueprintCallable, BlueprintPure)
    UBXEStatCounterComponent* GetBXEStatCounterComponent() const;

    UFUNCTION(BlueprintCallable, BlueprintPure)
    UBoosterDeckContainerComponent* GetBoosterDeckContainerComponent() const;

    UFUNCTION(BlueprintCallable, BlueprintPure)
    float GetBeginRevivedProgress() const;

    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent, BlueprintPure)
    UUsableComponent* GetBeastMasterUsableComponent() const;

    UFUNCTION(BlueprintCallable, BlueprintPure)
    FString GetAnalyticsClass() const;

    UFUNCTION(BlueprintCallable, BlueprintPure)
    FRotator GetAimRotation() const;

    UFUNCTION(BlueprintCallable, BlueprintPure)
    FVector GetActorGroundLocation() const;

    UFUNCTION(BlueprintCallable, BlueprintPure)
    TArray<AShieldGeneratorActor*> GetActiveShieldGenerators();

    UFUNCTION(BlueprintCallable, BlueprintPure)
    UPlayerAnimInstance* GetActiveAnimInstance() const;

    UFUNCTION(BlueprintCallable, BlueprintPure)
    static UAbilityData* GetAbilityData(APlayerCharacter* InCharacter);

    UFUNCTION(BlueprintCallable, BlueprintPure)
    UAbilityComponent* GetAbilityComponent() const;

    UFUNCTION(BlueprintCallable)
    void ForceIsPressingMovementInputKey();

    UFUNCTION(BlueprintAuthorityOnly, BlueprintCallable)
    void ExitVehicle();


    UFUNCTION(BlueprintCallable)
    void CycleItemUp();

    UFUNCTION(BlueprintCallable)
    void CycleItemReleased();

    UFUNCTION(BlueprintCallable)
    void CycleItemPressed();

    UFUNCTION(BlueprintCallable)
    void CycleItemDown();

public:
    UFUNCTION(BlueprintCallable)
    void ConsumeCycleItemButton();

    UFUNCTION(BlueprintCallable, Client, Reliable)
    void Client_TestGenerationDesync();

    UFUNCTION(BlueprintCallable, Client, Reliable)
    void Client_OpenMinersManual();

    UFUNCTION(BlueprintCallable, Client, Reliable)
    void Client_AddImpulse(const FVector_NetQuantizeNormal& Direction, float Force);

    UFUNCTION(BlueprintCallable, Client, Reliable)
    void Client_ActivateTemporaryBuff(UTemporaryBuff* buff);

    UFUNCTION(BlueprintAuthorityOnly, BlueprintCallable)
    void ChangeState(ECharacterState NewState);

    UFUNCTION(BlueprintAuthorityOnly, BlueprintCallable)
    void ChangeIfDifferentState(ECharacterState NewState);

    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool CanEscapeFromGrabber() const;


    UFUNCTION(BlueprintCallable)
    void CallDonkeyReleased();

    UFUNCTION(BlueprintCallable)
    void CallDonkeyPressed();

    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void BP_OnUpdateMeshes();

    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void BP_OnControllerReady();

public:
    UFUNCTION(BlueprintCallable)
    void AnnounceSchematicCollected(USchematic* InSchematic);


    UFUNCTION(BlueprintCallable, NetMulticast, Unreliable)
    void All_StartSalute(UAnimMontage* saluteMontage);

    UFUNCTION(BlueprintCallable, NetMulticast, Unreliable)
    void All_ShowImpactEffects(UFXSystemAsset* Particles, FVector_NetQuantize Location, FVector_NetQuantizeNormal Orientation) const;

public:
    UFUNCTION(BlueprintCallable, NetMulticast, Unreliable)
    void All_ShowFieldMedicInstantReviveEffects();

    UFUNCTION(BlueprintCallable, NetMulticast, Unreliable)
    void All_PlayCompletedUseMontage(UUseAnimationSetting* useSetting);

    UFUNCTION(BlueprintCallable, NetMulticast, Reliable)
    void All_OnCharacterUsedAirJump(APlayerCharacter* InPlayer);

    UFUNCTION(BlueprintCallable)
    void AddRunningBoostEffects(TArray<TSubclassOf<UStatusEffect>> effects);

    UFUNCTION(BlueprintCallable)
    void AddRunningBoostEffect(TSubclassOf<UStatusEffect> Effect);

    UFUNCTION(BlueprintCallable)
    void AddPlayerResource(UResourceData* Resource, float amount);

    UFUNCTION(BlueprintCallable)
    void AddImpulseToActor(AFSDPhysicsActor* Target, FVector_NetQuantize Impulse, FVector_NetQuantize Location, FVector_NetQuantize AngularImpulse);

    UFUNCTION(BlueprintCallable)
    void AddImpulseFromVector(const FVector& Vector);

    UFUNCTION(BlueprintCallable)
    void AddImpulseFromDirectionAndForce(const FVector& Direction, float Force);

    UFUNCTION(BlueprintAuthorityOnly, BlueprintCallable)
    void AddCloseFlare();


    UFUNCTION(BlueprintCallable, Reliable, Server)
    void AcknowledgeCharacterState(ECharacterState eState);

    UFUNCTION(BlueprintCallable)
    void AcceptInvite();


};

