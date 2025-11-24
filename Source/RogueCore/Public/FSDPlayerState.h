#pragma once
#include "CoreMinimal.h"
#include "GameFramework/PlayerState.h"
#include "CharacterProgress.h"
#include "ChipsReward.h"
#include "EChatSenderType.h"
#include "EGameOwnerStatus.h"
#include "EnemyKilledSignatureDelegate.h"
#include "EquippedVanity.h"
#include "FractionLevelGeneratedDelegateDelegate.h"
#include "LevelGenerationStateSignatureDelegate.h"
#include "PlayerNameChangedSignatureDelegate.h"
#include "PlayerSpawnedSignatureDelegate.h"
#include "PlayerVoiceSignatureDelegate.h"
#include "RewardTexts.h"
#include "SelectedCharacterChangedDelegateDelegate.h"
#include "SupplyStatusChangedDelegateDelegate.h"
#include "Templates/SubclassOf.h"
#include "XPReward.h"
#include "FSDPlayerState.generated.h"

class AFSDPlayerController;
class APlayerCharacter;
class UBXENegotiationParticipantComponent;
class UBXEPlayerStateComponent;
class UPerkAsset;
class UPlayerCharacterID;
class UPlayerRejoinState;
class UPlayerResourceComponent;
class UPlayerStatsComponent;
class URunHistoryStateComponent;
class USaveGameStateComponent;
class UVoteParticipantComponent;
UCLASS(Blueprintable, NoExport)
class ROGUECORE_API AFSDPlayerState : public APlayerState {
    GENERATED_BODY()
    // UPROPERTY fields moved from protected section

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, ReplicatedUsing=OnRep_GameOwnerStatus, meta=(AllowPrivateAccess=true))

    uint8 gameOwnerStatus;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, ReplicatedUsing=OnRep_PlayerCharacter, meta=(AllowPrivateAccess=true))

    APlayerCharacter* PlayerCharacter;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, ReplicatedUsing=OnRep_SupplyAmmoStatus, meta=(AllowPrivateAccess=true))

    uint8 SupplyAmmoStatus;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, ReplicatedUsing=OnRep_SupplyHealthStatus, meta=(AllowPrivateAccess=true))

    uint8 SupplyHealthStatus;



public:
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FPlayerSpawnedSignature OnPlayerCharacterSpawned;
    
    FPlayerVoiceSignature OnPlayerTalkingChanged;
    FSelectedCharacterChangedDelegate OnSelectedCharacterChanged;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, ReplicatedUsing=OnRep_FractionLevelGenerated, meta=(AllowPrivateAccess=true))
    float FractionLevelGenerated;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, ReplicatedUsing=OnRep_LevelGenerationState, meta=(AllowPrivateAccess=true))
    FString LevelGenerationState;
    FSupplyStatusChangedDelegate OnSupplyStatusChangedEvent;
    FEnemyKilledSignature OnEnemyKilledEvent;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Replicated, Transient, meta=(AllowPrivateAccess=true))
    FEquippedVanity LatestEquipedVanity;
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UBXEPlayerStateComponent* BXEStateComponent;
    UBXENegotiationParticipantComponent* BXENegotiationParticipant;
    UVoteParticipantComponent* VoteParticipant;
    URunHistoryStateComponent* RunHistoryStateComponent;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, ReplicatedUsing=OnRep_SelectedCharacter, meta=(AllowPrivateAccess=true))
    TSubclassOf<APlayerCharacter> SelectedCharacter;
    bool bIsServer;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool ShouldCopyProperties;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, ReplicatedUsing=OnRep_GameOwnerStatus, meta=(AllowPrivateAccess=true))
    uint8 gameOwnerStatus;
    bool IsOnSpaceRig;
    UPlayerStatsComponent* PlayerStatsComponent;
    UPlayerRejoinState* RejoinState;
    USaveGameStateComponent* SaveGameStateComponent;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, ReplicatedUsing=OnRep_PlayerCharacter, meta=(AllowPrivateAccess=true))
    APlayerCharacter* PlayerCharacter;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    bool IsInMission;
    bool IsTalking;
    bool HasGeneratedLevel;
    bool HasSelectedCharacter;
    int32 PlayerSortId;
    FPlayerNameChangedSignature OnPlayerNameChanged;
    FFractionLevelGeneratedDelegate OnFractionLevelGenerated;
    FLevelGenerationStateSignature OnLevelGenerationStateChanged;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, Transient, meta=(AllowPrivateAccess=true))
    UPlayerResourceComponent* PlayerResources;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, ReplicatedUsing=OnRep_SupplyAmmoStatus, meta=(AllowPrivateAccess=true))
    uint8 SupplyAmmoStatus;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, ReplicatedUsing=OnRep_SupplyHealthStatus, meta=(AllowPrivateAccess=true))
    uint8 SupplyHealthStatus;
    FRewardTexts RewardTexts;
    AFSDPlayerState(const FObjectInitializer& ObjectInitializer);
    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
    UFUNCTION(BlueprintCallable)
    void SetSelectedCharacterID(UPlayerCharacterID* characterID);
    void SetSelectedCharacter(TSubclassOf<APlayerCharacter> newCharacter);
    void SetHasGeneratedLevel(bool hasgenerated);
    void SetCanOnlySpectate(bool canOnlySpectate);
    UFUNCTION(BlueprintCallable, Reliable, Server)
    void ServerSetSelectedCharacter(TSubclassOf<APlayerCharacter> newCharacter);
    UFUNCTION(Reliable, Server, WithValidation)
    void ServerInitializePerks(const TArray<UPerkAsset*>& ClassPerks, const TArray<UPerkAsset*>& EnhancementPerks);
    void ServerInitializePerks_Implementation(const TArray<UPerkAsset*>& ClassPerks, const TArray<UPerkAsset*>& EnhancementPerks);
    UFUNCTION(Reliable, Server, WithValidation)
    void Server_SetSupplyStatus(uint8 StatusHealth, uint8 StatusAmmo);
    void Server_SetSupplyStatus_Implementation(uint8 StatusHealth, uint8 StatusAmmo);
    UFUNCTION(Reliable, Server, WithValidation)
    void Server_SetGameOwnerStatus(int32 NewGameOwnerStatus);
    void Server_SetGameOwnerStatus_Implementation(int32 NewGameOwnerStatus);
    UFUNCTION()
    void OnRep_SupplyHealthStatus();
    UFUNCTION()
    void OnRep_SupplyAmmoStatus();
    UFUNCTION()
    void OnRep_SelectedCharacter();
    UFUNCTION()
    void OnRep_PlayerCharacter();
    UFUNCTION()
    void OnRep_LevelGenerationState();
    UFUNCTION()
    void OnRep_GameOwnerStatus();
    UFUNCTION()
    void OnRep_FractionLevelGenerated();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnLateJoinFinished();

    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool HasNormalOwnerStatus() const;
    TArray<FXPReward> GetXPRewardRogueCore() const;
    UVoteParticipantComponent* GetVoteParticipant() const;
    int32 GetUIPing();
    float GetSupplyHealthStatus() const;
    float GetSupplyAmmoStatus() const;
    int32 GetSelectedCharacterLevel() const;
    UPlayerCharacterID* GetSelectedCharacterID() const;
    TSubclassOf<APlayerCharacter> GetSelectedCharacter() const;
    FCharacterProgress GetSelectCharacterProgress();
    URunHistoryStateComponent* GetRunHistoryStateComponent() const;
    UPlayerResourceComponent* GetPlayerResourceComponent() const;
    int32 GetPlayerRank() const;
    bool GetHasGeneratedLevel() const;
    bool GetGameOwnerStatus(EGameOwnerStatus status) const;
    AFSDPlayerController* GetFSDPlayerController() const;
    FChipsReward GetChipReward() const;
    EChatSenderType GetChatSenderType() const;
    FCharacterProgress GetCharacterProgress(UPlayerCharacterID* characterID) const;
    int32 GetCharacterLevel(UPlayerCharacterID* characterID) const;
    UBXENegotiationParticipantComponent* GetBXENegotiationParticipant() const;
    void CharacterSelected();
};
