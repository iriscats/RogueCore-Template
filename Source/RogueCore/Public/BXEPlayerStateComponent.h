#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "BXEPlayerData.h"
#include "BXESave.h"
#include "BXEStartLoadout.h"
#include "BXEUnlockInstance.h"
#include "ItemSlotIndex.h"
#include "ReadyUpState.h"
#include "BXEPlayerStateComponent.generated.h"

class AActor;
class AFSDPlayerState;
class UBXEPlayerStateComponent;
class UBXEStartingWeapon;
class UBXEUnlockBase;
class UBXEUnlockCollection;
class UItemUpgrade;
class UObject;
UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class ROGUECORE_API UBXEPlayerStateComponent : public UActorComponent {
    GENERATED_BODY()
    

public:
    DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FPlayerDataChanged, const FBXEPlayerData&, OldData, const AFSDPlayerState*, InPlayerState);
    DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FLoadoutChanged, UBXEPlayerStateComponent*, InBXEPlayerState);
    DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FLevelUpDelegate, int32, inLevel, const TArray<UBXEUnlockBase*>&, inUnlocks);
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FPlayerDataChanged OnPlayerDataChanged;
 
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, ReplicatedUsing=OnRep_PlayerData, meta=(AllowPrivateAccess=true))
    FBXEPlayerData PlayerData;
    FLoadoutChanged OnStartLoadoutChanged;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, ReplicatedUsing=OnRep_StartLoadOut, meta=(AllowPrivateAccess=true))
    FBXEStartLoadout StartLoadout;
    FLevelUpDelegate OnLevelUp;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<UBXEUnlockCollection*> CheatCollections;
    TArray<UBXEUnlockBase*> CheatUnlocks;
    UBXEPlayerStateComponent(const FObjectInitializer& ObjectInitializer);
    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
    UFUNCTION(BlueprintCallable)
    void SetUnlocksInBugReporter();
    UFUNCTION(BlueprintCallable, Reliable, Server)
    void Server_SetStartLoadout(const FBXEStartLoadout& InLoadout);
    UFUNCTION(BlueprintCallable, Reliable, Server)
    void Server_ReadyUp_SetIsReady();
    UFUNCTION(BlueprintCallable, Reliable, Server)
    void Server_ApplyUnlocksToPlayer(const TArray<FBXEUnlockInstance>& inUnlocks, const FItemSlotIndex InSlot);
    UFUNCTION(BlueprintCallable, Reliable, Server)
    void Server_AddWeaponAttributeToSlot(FItemSlotIndex InSlot, UItemUpgrade* InAttribute, AActor* PreviousActor);
    UFUNCTION()
    void OnRep_StartLoadOut(const FBXEStartLoadout& OldLoadout);
    UFUNCTION()
    void OnRep_PlayerData(const FBXEPlayerData& OldData);
    void OnBXESaveChanged(const FBXESave& InSave);
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FBXEUnlockInstance GetUnlockInSlot(FItemSlotIndex InSlot) const;
    UFUNCTION(BlueprintCallable, BlueprintPure, meta=(WorldContext="WorldContext"))
    int32 GetUnlockCount(UObject* WorldContext, UBXEUnlockBase* InUnlock) const;
    UBXEStartingWeapon* GetStartingWeapon() const;
    static UBXEPlayerStateComponent* GetLocalBXEPlayerState(const UObject* WorldContext);
    TArray<FBXEUnlockInstance> GetCurrentUnlocks(UObject* WorldContext) const;
    TArray<FBXEUnlockInstance> GetAllUnlocksInSlot(FItemSlotIndex InSlot) const;
    UFUNCTION(BlueprintCallable, Client, Reliable)
    void Client_ReceiveLevelUp(int32 inLevel, const TArray<UBXEUnlockBase*>& inUnlocks);
    UFUNCTION(BlueprintCallable, Client, Reliable)
    void Client_ReadyUp_SetState(const FReadyUpState& InState);
    UFUNCTION(BlueprintCallable, Reliable, Server, meta=(WorldContext="WorldContext"))
    void Cheat_StartNegotiation(UObject* WorldContext, UBXEUnlockCollection* InRewardPool);
    UFUNCTION(BlueprintCallable, Reliable, Server)
    void Cheat_RemoveUnlockFromPlayer(UBXEUnlockBase* InUnlock, FItemSlotIndex InSlot);
    void Cheat_PrintOutBXEStats();
    UFUNCTION(Exec)
    void Cheat_LevelUp();
    TArray<UBXEUnlockBase*> Cheat_GatherUnlocksForSlot(FItemSlotIndex InSlot);
    TArray<UBXEUnlockCollection*> Cheat_GatherNegotiationCollections();
    UFUNCTION(BlueprintCallable, Reliable, Server)
    void Cheat_ApplyUnlockToSoloDrone(UBXEUnlockBase* InUnlock, FItemSlotIndex InSlot, const TArray<UItemUpgrade*>& Attributes);
    UFUNCTION(BlueprintCallable, Reliable, Server)
    void Cheat_ApplyUnlockToPlayer(UBXEUnlockBase* InUnlock, FItemSlotIndex InSlot, const TArray<UItemUpgrade*>& Attributes);
    UFUNCTION(BlueprintCallable, Reliable, Server)
    void Cheat_AddXP_Player(int32 InXP);
    UFUNCTION(Exec)
    void Cheat_AddXP(int32 InXP);
};
