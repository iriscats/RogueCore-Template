#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "ActiveCampaingMission.h"
#include "CharacterProgress.h"
#include "CharacterProgressChangedSignatureDelegate.h"
#include "ItemLoadout.h"
#include "ItemUpgradeSelection.h"
#include "LoadoutChangedDelegateDelegate.h"
#include "PlayerProgress.h"
#include "PlayerProgressChangedSignatureDelegate.h"
#include "Templates/SubclassOf.h"
#include "SaveGameStateComponent.generated.h"

class AActor;
class UItemUpgrade;
class UPlayerCharacterID;
class UStage;
class UVictoryPose;
UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class USaveGameStateComponent : public UActorComponent {
    GENERATED_BODY()
    // UPROPERTY fields moved from protected section

public:
    DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FItemUpgradeEquipSignature, TSubclassOf<AActor>, itemClass, UItemUpgrade*, upgrade);
    DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FItemUpgradeCraftSignature, UItemUpgrade*, upgrade);
    DECLARE_DYNAMIC_MULTICAST_DELEGATE(FCreditsChangedDelegate);
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FPlayerProgressChangedSignature OnPlayerProgressChanged;
    FLoadoutChangedDelegate OnLoadoutChangedEvent;
    FCharacterProgressChangedSignature OnCharacterStatsChanged;
    FCreditsChangedDelegate OnCreditsChanged;
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, ReplicatedUsing=OnRep_Credits, meta=(AllowPrivateAccess=true))
    int32 Credits;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Replicated, Transient, meta=(AllowPrivateAccess=true))
    UVictoryPose* VictoryPose;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    FItemLoadout EquippedLoadout;
    FActiveCampaingMission ActiveCampaignMission;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, ReplicatedUsing=OnRep_ItemUpgradeSelections, meta=(AllowPrivateAccess=true))
    TArray<FItemUpgradeSelection> ItemUpgradeSelections;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, ReplicatedUsing=OnRep_PlayerProgress, meta=(AllowPrivateAccess=true))
    FPlayerProgress PlayerProgress;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, ReplicatedUsing=OnRep_CharacterStats, meta=(AllowPrivateAccess=true))
    TArray<FCharacterProgress> CharacterStats;
    USaveGameStateComponent(const FObjectInitializer& ObjectInitializer);
    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
    UFUNCTION(BlueprintCallable)
    void SetCampaign();
    UFUNCTION(BlueprintCallable, Reliable, Server)
    void Server_SetVictoryPose(UVictoryPose* Pose);
    void Server_SetPlayerProgress(const FPlayerProgress& Progress);
    void Server_SetLoadout(const FItemLoadout& Loadout, const TArray<FItemUpgradeSelection>& weaponLoadouts);
    void Server_SetCredits(const int32 amount);
    void Server_SetCharacterStats(const TArray<FCharacterProgress>& Stats);
    void Server_SetActiveCampaignMission(FActiveCampaingMission Data);
    void RefreshLoadoutFromSave(UPlayerCharacterID* characterID);
    UFUNCTION()
    void OnRep_PlayerProgress();
    UFUNCTION()
    void OnRep_ItemUpgradeSelections();
    UFUNCTION()
    void OnRep_Credits();
    UFUNCTION()
    void OnRep_CharacterStats();
    FCharacterProgress GetCharacterStat(UPlayerCharacterID* characterID);
    UFUNCTION(BlueprintCallable, BlueprintPure)
    UStage* GetActiveCampaignMission() const;
};
