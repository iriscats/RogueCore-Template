#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "GameFramework/Actor.h"
#include "UObject/UnrealType.h"
#include "AudioWithCooldown.h"
#include "DelegateDelegate.h"
#include "ItemIDInterface.h"
#include "ItemLoadoutAnimations.h"
#include "LoadoutItem.h"
#include "PlaySoundInterface.h"
#include "SaveGameIDInterface.h"
#include "Skinnable.h"
#include "Templates/SubclassOf.h"
#include "Item.generated.h"

class ACharacter;
class AItem;
class APlayerCharacter;
class UAudioComponent;
class UBXEUnlockBase;
class UCameraShakeBase;
class UCurveFloat;
class UDialogDataAsset;
class UElementType;
class UFirstPersonStaticMeshComponent;
class UItemCharacterAnimationSet;
class UItemID;
class UItemUpgrade;
class UItemsBarIcon;
class USceneComponent;
class USkinEffect;
class USoundAttenuation;
class USoundBase;
class USoundClass;
class USoundConcurrency;
class UStaticMeshComponent;
class UTexture2D;
class UUpgradableItemComponent;
UCLASS(Abstract, Blueprintable)
class ROGUECORE_API AItem : public AActor, public ISaveGameIDInterface, public ISkinnable, public IItemIDInterface, public ILoadoutItem, public IPlaySoundInterface {
    GENERATED_BODY()
    

public:
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FDelegate OnAddedToInventoryDelegate;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FVector FPCameraOffset;
    FAudioWithCooldown AudioFriendlyFire;
    FDelegate OnRemovedFromStorage;
    FDelegate OnEqipped;
    FDelegate OnUnequipped;
    FDelegate OnOverHeatedDelegate;
    FDelegate OnStartedUsing;
    bool EnableDangerousSaveGameIDEditing;
    FGuid SavegameID;
    UItemID* ItemID;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    APlayerCharacter* Character;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UUpgradableItemComponent* UpgradableItem;
    FName AttachSocket;
    EAttachmentRule AttachRule;
    EDetachmentRule DetachRule;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, ReplicatedUsing=OnRep_Attributes, meta=(AllowPrivateAccess=true))
    TArray<UItemUpgrade*> Attributes;
    TSubclassOf<UCameraShakeBase> CameraShake;
    bool CameraShakeOnStartUsing;
    bool CameraShakeOnEquip;
    UCurveFloat* HeatCurve;
    float ManualHeatPerUse;
    float CooldownRate;
    float ManualCooldownDelay;
    float UnjamDuration;
    float CurrentTemperature;
    USoundBase* AudioTemperature;
    float AudioTemperatureFadeout;
    FName TemperatureFloatParam;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, Transient, meta=(AllowPrivateAccess=true))
    UAudioComponent* TemperatureAudioComponent;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Replicated, meta=(AllowPrivateAccess=true))
    bool overheated;
    UDialogDataAsset* ShoutOverheated;
    bool bAimAssistEnabled;
    float MovementRateWhileUsing;
    bool CanPlayLedgeClimbWhileUsing;
    bool CanInspectItem;
    bool CanSprintWithItem;
    TSubclassOf<UItemsBarIcon> CustomIconWidget;
    float AdvancedVibrationSendLevel;
    bool IsEquipped;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, ReplicatedUsing=OnRep_IsUsing, meta=(AllowPrivateAccess=true))
    bool isUsing;
    TArray<UElementType*> ActiveElementTypes;
    AItem(const FObjectInitializer& ObjectInitializer);
    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
    UFUNCTION(BlueprintCallable)
    void UpdateSkin();
    UAudioComponent* SpawnSoundAttached(USoundBase* Sound, USceneComponent* AttachToComponent, float PriorityOverride, FName AttachPointName, FVector Location, FRotator Rotation, TEnumAsByte<EAttachLocation::Type> LocationType, bool bStopWhenAttachedToDestroyed, float VolumeMultiplier, float PitchMultiplier, float StartTime, USoundAttenuation* AttenuationSettings, USoundConcurrency* ConcurrencySettings, USoundClass* soundClassOverride, bool bAutoDestroy, bool SendVibration);
    UAudioComponent* SpawnSoundAtLocation(USoundBase* Sound, FVector Location, FRotator Rotation, float VolumeMultiplier, float PitchMultiplier, float StartTime, USoundAttenuation* AttenuationSettings, USoundConcurrency* ConcurrencySettings, bool bAutoDestroy, bool SendVibration);
    UAudioComponent* SpawnSound2D(USoundBase* Sound, float PriorityOverride, float VolumeMultiplier, float PitchMultiplier, float StartTime, USoundConcurrency* ConcurrencySettings, bool bPersistAcrossLevelTransition, bool bAutoDestroy, bool SendVibration);
    UFUNCTION(BlueprintCallable, Reliable, Server)
    void Server_StartUsing(bool NewIsUsing);
    void Resupply(float percentage);
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void RemovedFromInventory(ACharacter* oldCharacter);
    void RecieveUnequipped();
    void RecieveStopUsing();
    void RecieveStartUsing();
    void RecieveEquipped();
    void RecieveCycledItem();
    void Recieve_UpdateMeshses(bool NewIsFirstPerson);
    void ReceiveResupply(float percentage);
    void Receive_Overheated();
    UStaticMeshComponent* Receive_GetTPAnimationEventMesh() const;
    UFirstPersonStaticMeshComponent* Receive_GetFPAnimationEventMesh() const;
    void OnTemperatureChanged(float temperature, bool NewOverheated);
    void OnSkinChanged(USkinEffect* Skin);
    UFUNCTION()
    void OnRep_IsUsing(bool OldValue);
    UFUNCTION()
    void OnRep_Attributes();
    void OnOwnerDestroyed(AActor* owningActor);
    void OnCharacterLevelUp(int32 inLevel, const TArray<UBXEUnlockBase*>& inUnlocks);
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsLocallyControlled() const;
    bool IsFirstPerson() const;
    TSubclassOf<AActor> GetWeaponViewClass() const;
    FItemLoadoutAnimations GetLoadoutAnimations() const;
    FText GetItemName() const;
    UTexture2D* GetItemIconLine() const;
    UTexture2D* GetItemIconBG() const;
    static AItem* GetItemDefaultObject(TSubclassOf<AItem> itemClass);
    FText GetItemCategory() const;
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    USceneComponent* GetHeatingAudioSceneComponent();
    UItemCharacterAnimationSet* GetCharacterAnimationSet() const;
    FString GetAnalyticsItemName() const;
    FString GetAnalyticsItemCategory() const;
    void AddedToInventory(APlayerCharacter* ItemOwner);
    // Fix for true pure virtual functions not being implemented
    TSubclassOf<AItem> GetLoadoutItemClass() const override PURE_VIRTUAL(GetLoadoutItemClass, return NULL;);
};
