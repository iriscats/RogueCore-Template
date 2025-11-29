#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "PerkState.h"
#include "PerkComponent.generated.h"

class UPerkAsset;
UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class UPerkComponent : public UActorComponent {
    GENERATED_BODY()
    

public:
    DECLARE_DYNAMIC_MULTICAST_DELEGATE(FPerkDelegate);
    DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FPerkComponentDelegate, UPerkAsset*, Perk);
    
 
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FPerkDelegate OnActivePerksChanged;
    FPerkComponentDelegate OnPerkUsabilityChanged;
 
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Replicated, Transient, meta=(AllowPrivateAccess=true))
    TArray<UPerkAsset*> ClassPerks;
    TArray<UPerkAsset*> EnhancementPerks;
    TArray<UPerkAsset*> CustomPerks;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    bool CanActivatePerks;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, ReplicatedUsing=OnActivePerksReplicated, meta=(AllowPrivateAccess=true))
    TArray<FPerkState> ActivePerks;
    TArray<UPerkAsset*> LocallyActivatedPerks;
    TArray<UPerkAsset*> LocallyUsablePerks;
    UPerkComponent(const FObjectInitializer& ObjectInitializer);
    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
    UFUNCTION(BlueprintCallable)
    void SetUseCount(const UPerkAsset* Perk, const int32 NewUseCount);
    void SetPerksActive(const bool NewActive);
    void SetPerkBlocked(const UPerkAsset* Perk, const bool IsBlocked);
    void SetMaximumUses(const UPerkAsset* Perk, const int32 NewMaximumUses);
    void SetEnhancementPerks(const TArray<UPerkAsset*>& NewEnhancementPerks);
    void SetCooldown(const UPerkAsset* Perk, const float NewCooldown);
    void SetClassPerks(const TArray<UPerkAsset*>& NewClassPerks);
    UFUNCTION(BlueprintCallable, Reliable, Server)
    void Server_SetUseCount(const UPerkAsset* Perk, const int32 NewUseCount);
    UFUNCTION(BlueprintCallable, Reliable, Server)
    void Server_SetPerkBlocked(const UPerkAsset* Perk, const bool IsBlocked);
    UFUNCTION(BlueprintCallable, Reliable, Server)
    void Server_SetMaximumUses(const UPerkAsset* Perk, const int32 NewMaxUses);
    UFUNCTION(BlueprintCallable, Reliable, Server)
    void Server_SetCooldown(const UPerkAsset* Perk, const float NewCooldown);
    UFUNCTION(BlueprintCallable, Reliable, Server)
    void Server_ResetPerkStates();
    UFUNCTION(BlueprintCallable, Reliable, Server)
    void Server_ResetPerkState(const UPerkAsset* Perk);
    UFUNCTION(BlueprintCallable, Reliable, Server)
    void Server_IncrementUseCount(const UPerkAsset* Perk);
    void ResetPerkStates();
    void ResetPerkState(const UPerkAsset* Perk);
    UFUNCTION()
    void OnActivePerksReplicated(const TArray<FPerkState>& OldActivePerks);
    void MarkPerkUsed(const UPerkAsset* Perk);
    UFUNCTION(BlueprintCallable, BlueprintPure)
    int32 GetUseCount(const UPerkAsset* Perk) const;
    int32 GetRemainingUses(const UPerkAsset* Perk) const;
    int32 GetMaximumUses(const UPerkAsset* Perk) const;
    TArray<UPerkAsset*> GetEnhancementPerks() const;
    TArray<UPerkAsset*> GetCustomPerks() const;
    float GetCoolDownProgress(const UPerkAsset* Perk) const;
    float GetCooldown(const UPerkAsset* Perk) const;
    TArray<UPerkAsset*> GetClassPerks() const;
    TArray<UPerkAsset*> GetActivePerks() const;
    bool ContainsPerk(const UPerkAsset* Perk) const;
    bool CanUsePerk(const UPerkAsset* Perk) const;
    void AddCustomPerk(UPerkAsset* NewCustomPerk);
};
