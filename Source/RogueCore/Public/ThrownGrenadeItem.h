#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "EThrownGrenadeItemState.h"
#include "Item.h"
#include "RejoinListener.h"
#include "Templates/SubclassOf.h"
#include "ThrownGrenadeItem.generated.h"

class AGrenade;
class UFSDAudioComponent;
class UGrenadeAnimationSet;
class UGrenadeCountAggregator;
class UItemCharacterAnimationSet;
class UPlayerAnimInstance;
class UStaticMeshComponent;
UCLASS(Blueprintable, NoExport)
class AThrownGrenadeItem : public AItem, public IRejoinListener {
    GENERATED_BODY()
    // UPROPERTY fields moved from protected section

public:
    DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnGrenadeThrown);
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOnGrenadeThrown OnGrenadeThrown;
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FVector ThrowOffset;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, Transient, meta=(AllowPrivateAccess=true))
    UStaticMeshComponent* GrenadeMeshInstance;
    UFSDAudioComponent* CookSound;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGrenadeCountAggregator* Aggregator;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    UPlayerAnimInstance* FPAnimInstance;
    UPlayerAnimInstance* TPAnimInstance;
    UItemCharacterAnimationSet* CharacterAnimationSet;
    UGrenadeAnimationSet* DefaultGrenadeAnimationSet;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, ReplicatedUsing=OnRep_GrenadeClass, meta=(AllowPrivateAccess=true))
    TSubclassOf<AGrenade> GrenadeClass;
    float ThrowAngle;
    float GrenadeCooldownRemaining;
    int32 MaxGrenades;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, ReplicatedUsing=OnRep_GrenadeCount, meta=(AllowPrivateAccess=true))
    int32 Grenades;
    UPROPERTY(EditAnywhere, Transient, ReplicatedUsing=OnRep_State, meta=(AllowPrivateAccess=true))
    EThrownGrenadeItemState State;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Replicated, Transient, meta=(AllowPrivateAccess=true))
    bool CooldownIsDone;
    bool HasRejoinedInitialized;
    AThrownGrenadeItem(const FObjectInitializer& ObjectInitializer);
    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void UpdateCookTime(float Time);
    UFUNCTION(BlueprintCallable)
    void SetRemainingCooldown(float CoolDown);
    UFUNCTION(BlueprintCallable, Reliable, Server)
    void Server_ThrowGrenade(const FVector& StartLocation, const float& cookTime);
    UFUNCTION(Reliable, Server)
    void Server_SetState(EThrownGrenadeItemState itemState);
    void Server_Resupply(float percentage);
    void Server_HasReturnedToSender();
    void ResupplyGrenadesAmount(const int32& amount);
    void ResupplyGrenades(float percentage);
    TArray<FVector> PredictGrenadePath();
    void OnShowGrenadePath();
    UFUNCTION()
    void OnRep_State();
    UFUNCTION()
    void OnRep_GrenadeCount();
    UFUNCTION()
    void OnRep_GrenadeClass();
    void OnHideGrenadePath();
    void GrenadeThrowFinished();
    void GetPredictedLastPosAndVelocity(FVector& Pos, FVector& Velocity);
    UFUNCTION(BlueprintCallable, BlueprintPure)
    float GetGrenadeThrowVelocity() const;
    FRotator GetGrenadeThrowRotation() const;
    float GetGrenadeGravity() const;
    float GetGrenadeDuration() const;
    // Fix for true pure virtual functions not being implemented
};
