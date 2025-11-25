#pragma once
#include "CoreMinimal.h"
#include "Engine/NetSerialization.h"
#include "RewardDispenserBase.h"
#include "RewardDispenserReward.h"
#include "GenericRewardDispenser.generated.h"

class AEventRewardFrame;
class AFSDPlayerState;
class APlayerCharacter;
UCLASS(Abstract, Blueprintable)
class AGenericRewardDispenser : public ARewardDispenserBase {
    GENERATED_BODY()
    // UPROPERTY fields moved from protected section

public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, ReplicatedUsing=OnRep_PlayerId, meta=(AllowPrivateAccess=true))
    FUniqueNetIdRepl PlayerId;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    AEventRewardFrame* DispenserFrame;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, ReplicatedUsing=OnRep_SelectedReward, meta=(AllowPrivateAccess=true))
    FRewardDispenserReward SelectedReward;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, ReplicatedUsing=OnRep_PoweredUp, meta=(AllowPrivateAccess=true))
    bool PoweredUp;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, ReplicatedUsing=OnRep_IsActivated, meta=(AllowPrivateAccess=true))
    bool IsActivated;
    AGenericRewardDispenser(const FObjectInitializer& ObjectInitializer);
    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
    UFUNCTION(BlueprintAuthorityOnly, BlueprintCallable)
    bool PowerUp(APlayerCharacter* InPlayerCharacter);
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnRewardSelected();
    UFUNCTION(BlueprintCallable)
    void OnRep_SelectedReward();
    UFUNCTION()
    void OnRep_PoweredUp();
    UFUNCTION()
    void OnRep_PlayerId();
    UFUNCTION()
    void OnRep_IsActivated();
    void OnPoweredUp();
    void OnOwnerAssigned();
    void OnOpenDispenser();
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsOwningPlayer(APlayerCharacter* PlayerCharacter) const;
    FRewardDispenserReward GetSelectedReward() const;
    APlayerCharacter* GetPlayerCharacter() const;
    AFSDPlayerState* GetPlayer() const;
};
