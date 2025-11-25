#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "ChatOpenedDelegateDelegate.h"
#include "ClientDamageRapport.h"
#include "ClientRadialDamageRapport.h"
#include "EAbilityActivationMode.h"
#include "EArmorDamageType.h"
#include "EChatSenderType.h"
#include "ESpacerigStartType.h"
#include "FSDPlayerControllerBase.h"
#include "OnPlayerCharacterPossesedDelegate.h"
#include "Templates/SubclassOf.h"
#include "FSDPlayerController.generated.h"

class AActor;
class ADeepPathfinderCharacter;
class AFSDPlayerState;
class AHUD;
class APlayerCharacter;
class UDamageComponent;
class UFSDAchievement;
class UFSDWidgetEffectsComponent;
class UItemID;
class UItemSkin;
class UPickaxePart;
class UPlayerCharacterID;
class USimpleArmorDamageComponent;
class USkinTreasureRewarder;
class USoundCue;
class USoundMix;
class UTerrainLatejoinComponent;
class UTexture2D;
class UTreasureRewarder;
class UTutorialContentWidget;
class UVanityItem;
class UVictoryPose;
UCLASS(Blueprintable, NoExport)
class ROGUECORE_API AFSDPlayerController : public AFSDPlayerControllerBase {
    GENERATED_BODY()
    // UPROPERTY fields moved from protected section

public:
    DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FReceivingVoiceSignature, bool, isRecieving);
    DECLARE_DYNAMIC_MULTICAST_DELEGATE(FReceivedEndLevelDelegate);
    DECLARE_DYNAMIC_MULTICAST_DELEGATE_FiveParams(FOnShowTutorialHint, const FText&, Text, const FText&, Title, const FText&, TaskText, UTexture2D*, Image, float, Duration);
    DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnHideTutorialHint, bool, wasWatched);
    DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnChangeTutorialWidget, TSubclassOf<UTutorialContentWidget>, TutorialWidget, bool, bIgnoreQueue);
    DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnChangeTutorialHintDuration, float, NewDuration);
    DECLARE_DYNAMIC_MULTICAST_DELEGATE(FLevelFinishedSignature);
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FLevelFinishedSignature OnDiveStageCompleted;
    FLevelFinishedSignature OnDiveRunCompleted;
    FReceivedEndLevelDelegate OnEndLevelReceived;
    FReceivingVoiceSignature OnReceiveVoiceChanged;
    FReceivingVoiceSignature OnTransmitVoiceChanged;
    FOnShowTutorialHint OnShowTutorialHint;
    FOnChangeTutorialWidget OnShowTutorialWidget;
    FOnChangeTutorialHintDuration OnChangeTutorialHintDuration;
    FOnHideTutorialHint OnHideCurrentTutorialHint;
    FOnPlayerCharacterPossesed OnPlayerCharacterPossesed;
    UPROPERTY(BlueprintAssignable, BlueprintCallable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FChatOpenedDelegate OnChatOpened;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Replicated, meta=(AllowPrivateAccess=true))
    ADeepPathfinderCharacter* DebugEnemy;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, ReplicatedUsing=OnRep_DebugEnemyLocation, meta=(AllowPrivateAccess=true))
    FVector DebugEnemyLocation;
    float DebugEnemySpeed;
    float DebugEnemySpeedMod;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    ADeepPathfinderCharacter* DebugEnemyLast;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UTerrainLatejoinComponent* LateJoinComponent;
    bool IsOnSpaceRig;
    TArray<USoundMix*> InitialSoundMixes;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    bool ServerTravelDone;
    UFSDWidgetEffectsComponent* WidgetEffects;
    ESpacerigStartType SpacerigSpawnType;
    bool bDetectGravityChanges;
    bool bReceivedEndLevel;
    AFSDPlayerController(const FObjectInitializer& ObjectInitializer);
    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
    UFUNCTION(BlueprintCallable)
    void ToggleVoiceOn(bool Enabled);

    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void StartLevelEndSequenceWhenReady();
    
    void StartLevelEndSequence(const bool ShowEndScreen);
    void SpawnHUDLocal(TSubclassOf<AHUD> hudClass);
    void SpawnHUDAsync();
    void ShowTutorialWidget(TSubclassOf<UTutorialContentWidget> TutorialWidget, bool ignoreQueue);
    void ShowTutorialHint(const FText& Text, const FText& Title, const FText& TaskText, UTexture2D* Image, float Duration);
    void SetPlayerStart(AActor* Start);
    UFUNCTION(BlueprintCallable, Client, Reliable)
    void SetAchievementProgressFromServer(UFSDAchievement* AchievementToSet, float Progress);
    UFUNCTION(BlueprintCallable, Reliable, Server)
    void ServerSetUserHoldToRun(bool Value);
    UFUNCTION(Reliable, Server, WithValidation)
    void Server_TravelDone();
    void Server_TravelDone_Implementation();
    UFUNCTION(Reliable, Server, WithValidation)
    void Server_TakeDamageFrom(UDamageComponent* Damage, FVector Location);
    void Server_TakeDamageFrom_Implementation(UDamageComponent* Damage, FVector Location);
    UFUNCTION(Reliable, Server, WithValidation)
    void Server_StartNamedCountdownWithQuickFinish(const FName Name, const int32 CountdownSeconds);
    void Server_StartNamedCountdownWithQuickFinish_Implementation(const FName Name, const int32 CountdownSeconds);
    UFUNCTION(Reliable, Server, WithValidation)
    void Server_StartNamedCountdown(const FName Name, const int32 CountdownSeconds);
    void Server_StartNamedCountdown_Implementation(const FName Name, const int32 CountdownSeconds);
    UFUNCTION(Reliable, Server, WithValidation)
    void Server_SetLateJoinDone();
    void Server_SetLateJoinDone_Implementation();
    UFUNCTION(Reliable, Server, WithValidation)
    void Server_SetGenerationStatus(const FString& status, float Fraction);
    void Server_SetGenerationStatus_Implementation(const FString& status, float Fraction);
    UFUNCTION(Reliable, Server, WithValidation)
    void Server_SetGenerationFraction(float Fraction);
    void Server_SetGenerationFraction_Implementation(float Fraction);
    UFUNCTION(Reliable, Server, WithValidation)
    void Server_SetGenerationDone();
    void Server_SetGenerationDone_Implementation();
    UFUNCTION(Reliable, Server, WithValidation)
    void Server_SetDebugEnemy(ADeepPathfinderCharacter* NewDebugEnemy);
    void Server_SetDebugEnemy_Implementation(ADeepPathfinderCharacter* NewDebugEnemy);
    UFUNCTION(Reliable, Server, WithValidation)
    void Server_SetControllerReady();
    void Server_SetControllerReady_Implementation();
    UFUNCTION(Reliable, Server, WithValidation)
    void Server_ResetNamedCountdown(const FName Name);
    void Server_ResetNamedCountdown_Implementation(const FName Name);
    UFUNCTION(Reliable, Server, WithValidation)
    void Server_ResetHUD();
    void Server_ResetHUD_Implementation();
    UFUNCTION(Reliable, Server, WithValidation)
    void Server_Relay_SetArmorIndexDestroyed(USimpleArmorDamageComponent* ArmorComponent, int32 Index, EArmorDamageType DamageType);
    void Server_Relay_SetArmorIndexDestroyed_Implementation(USimpleArmorDamageComponent* ArmorComponent, int32 Index, EArmorDamageType DamageType);
    UFUNCTION(Reliable, Server, WithValidation)
    void Server_ReceiveClientRadialDamageRapport(const FClientRadialDamageRapport& rapport);
    void Server_ReceiveClientRadialDamageRapport_Implementation(const FClientRadialDamageRapport& rapport);
    UFUNCTION(Reliable, Server, WithValidation)
    void Server_ReceiveClientDamageRapport(const FClientDamageRapport& rapport);
    void Server_ReceiveClientDamageRapport_Implementation(const FClientDamageRapport& rapport);
    UFUNCTION(Reliable, Server, WithValidation)
    void Server_NewMessage(const FString& Sender, const FString& Text, EChatSenderType SenderType);
    void Server_NewMessage_Implementation(const FString& Sender, const FString& Text, EChatSenderType SenderType);
    UFUNCTION(Reliable, Server, WithValidation)
    void Server_DrawProjectileDebugPath(bool bDraw);
    void Server_DrawProjectileDebugPath_Implementation(bool bDraw);
    void SendLevelUpStatistics(const int32 currentRank);
    void RecievePawnDestroyed();
    void RecieveOnControllerReady();
    void Receive_MenuButtonReleased();
    void OnStartLevelEndSequence(const bool ShowEndScreen);
    void OnSaveGamePlayerProgressChanged(int32 Rank, int32 Stars);
    void OnSaveGameCreditsChanged(int32 Credits);
    void OnSaveGameCharacterProgressChanged(TSubclassOf<APlayerCharacter> CharacterClass, int32 Level, float Progress);
    UFUNCTION()
    void OnRep_DebugEnemyLocation();
    void OnPlayerStateSelectedCharacterChanged(TSubclassOf<APlayerCharacter> CharacterClass);
    void OnPlayerSpawnBegin(int32 PlayerId);
    UFUNCTION(BlueprintImplementableEvent)
    void OnLevelEnd();
    void OnLevelEnd_Implementation();
    void OnGenerationDone();
    void HideTutorialHint(bool watched);
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool GetUseToggleTerrainScanner();
    bool GetUseToggleLaserPointer();
    bool GetUseHoldToRun();
    AActor* GetPlayerStart();
    AFSDPlayerState* GetFSDPlayerState() const;
    bool GetEndLevelFlagSet() const;
    EAbilityActivationMode GetAbilityActivationMode();
    void FlushRender();
    AActor* FindPlayerStart(UPlayerCharacterID* characterID);
    UFUNCTION(Client, Reliable)
    void Client_PlayCue(USoundCue* SoundCue);
    void Client_PlayCue_Implementation(USoundCue* SoundCue);
    UFUNCTION(Client, Reliable)
    void Client_CollectVanityItem(UTreasureRewarder* rewarder, UVanityItem* targetItem, UPlayerCharacterID* targetCharacter);
    void Client_CollectVanityItem_Implementation(UTreasureRewarder* rewarder, UVanityItem* targetItem, UPlayerCharacterID* targetCharacter);
    UFUNCTION(Client, Reliable)
    void Client_CollectTreasureVictoryPose(UTreasureRewarder* rewarder, UVictoryPose* targetPose, UPlayerCharacterID* targetCharacter);
    void Client_CollectTreasureVictoryPose_Implementation(UTreasureRewarder* rewarder, UVictoryPose* targetPose, UPlayerCharacterID* targetCharacter);
    UFUNCTION(Client, Reliable)
    void Client_CollectTreasureSkin(USkinTreasureRewarder* rewarder, UItemSkin* targetSkin, UItemID* targetItem);
    void Client_CollectTreasureSkin_Implementation(USkinTreasureRewarder* rewarder, UItemSkin* targetSkin, UItemID* targetItem);
    UFUNCTION(Client, Reliable)
    void Client_CollectPickaxePart(const UTreasureRewarder* rewarder, UPickaxePart* targetPart);
    void Client_CollectPickaxePart_Implementation(const UTreasureRewarder* rewarder, UPickaxePart* targetPart);
    void ApplyLevelEndResultsAndNotifyServer();
};
