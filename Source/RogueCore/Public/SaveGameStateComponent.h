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
    

public:
    DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FItemUpgradeEquipSignature, TSubclassOf<AActor>, itemClass, UItemUpgrade*, upgrade);
    DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FItemUpgradeCraftSignature, UItemUpgrade*, upgrade);
    DECLARE_DYNAMIC_MULTICAST_DELEGATE(FCreditsChangedDelegate);
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FPlayerProgressChangedSignature OnPlayerProgressChanged;
    FLoadoutChangedDelegate OnLoadoutChangedEvent;
    FCharacterProgressChangedSignature OnCharacterStatsChanged;
    FCreditsChangedDelegate OnCreditsChanged;
 
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
    UFUNCTION(Reliable, Server)
    void Server_SetPlayerProgress(const FPlayerProgress& Progress);
    UFUNCTION(Reliable, Server)
    void Server_SetLoadout(const FItemLoadout& Loadout, const TArray<FItemUpgradeSelection>& weaponLoadouts);
    UFUNCTION(Reliable, Server)
    void Server_SetCredits(const int32 amount);
    UFUNCTION(Reliable, Server)
    void Server_SetCharacterStats(const TArray<FCharacterProgress>& Stats);
    UFUNCTION(Reliable, Server)
    void Server_SetActiveCampaignMission(FActiveCampaingMission Data);
    UFUNCTION(Reliable, Server)
    void RefreshLoadoutFromSave(UPlayerCharacterID* characterID);
    UFUNCTION()
    void OnRep_PlayerProgress();
    UFUNCTION()
    void OnRep_ItemUpgradeSelections();
    UFUNCTION()
    void OnRep_Credits();
    UFUNCTION()
    void OnRep_CharacterStats();
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FCharacterProgress GetCharacterStat(UPlayerCharacterID* characterID);
    UFUNCTION(BlueprintCallable, BlueprintPure)
    UStage* GetActiveCampaignMission() const;
};
