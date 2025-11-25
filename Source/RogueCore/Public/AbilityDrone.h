#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Engine/NetSerialization.h"
#include "GameplayTagContainer.h"
#include "AbilityDroneStateDelegateDelegate.h"
#include "DeepPathfinderCharacter.h"
#include "DelegateDelegate.h"
#include "DroneControllerUseInfo.h"
#include "EAbilityDroneState.h"
#include "Minion.h"
#include "RandRange.h"
#include "Templates/SubclassOf.h"
#include "AbilityDrone.generated.h"

class AActor;
class APlayerCharacter;
class AProjectile;
class UAudioComponent;
class UBehaviorTree;
class UDamageNumberAggregator;
class UPerkAsset;
UCLASS(Blueprintable)
class AAbilityDrone : public ADeepPathfinderCharacter, public IMinion {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UAudioComponent* MovementAudio;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FDelegate OnAttack;
    FAbilityDroneStateDelegate OnEnterStateDelegate;
    FAbilityDroneStateDelegate OnExitStateDelegate;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGameplayTagQuery TargetQuery;
    UDamageNumberAggregator* DamageNumberAggregator;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, ReplicatedUsing=OnRep_TeleportLocation, meta=(AllowPrivateAccess=true))
    FVector_NetQuantize TeleportLocation;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TWeakObjectPtr<AActor> BurstTarget;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, ReplicatedUsing=OnRep_ShotCounter, meta=(AllowPrivateAccess=true))
    uint8 ShotCounter;
    TWeakObjectPtr<APlayerCharacter> ControllingCharacter;
    UBehaviorTree* BehaviourTree;
    TSubclassOf<AProjectile> ProjectileClass;
    float AttackRange;
    float AttackInterval;
    FRandRange BurstInterval;
    bool AllowAutomaticRevive;
    int32 BurstSize;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, ReplicatedUsing=OnRep_State, meta=(AllowPrivateAccess=true))
    EAbilityDroneState State;
    float ReviveSearchRange;
    UPerkAsset* RevivePerk;
 
    AAbilityDrone(const FObjectInitializer& ObjectInitializer);
    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
    UFUNCTION(BlueprintAuthorityOnly, BlueprintCallable)
    void SetState(EAbilityDroneState NewState);
    UFUNCTION(BlueprintCallable, Server, Unreliable)
    void Server_SecondaryUsed(const FDroneControllerUseInfo& Info);
    void Server_PrimaryUsed(const FDroneControllerUseInfo& Info);
    UFUNCTION()
    void Server_PrimaryUsed_Implementation(const FDroneControllerUseInfo& Info);
    UFUNCTION(BlueprintCallable)
    void SearchPulse();
    UFUNCTION()
    void OnRep_TeleportLocation();
    UFUNCTION()
    void OnRep_State(EAbilityDroneState oldState);
    UFUNCTION()
    void OnRep_ShotCounter();
    void ControllerSecondaryUsed(const FDroneControllerUseInfo& Info);
    void ControllerPrimaryUsed(const FDroneControllerUseInfo& Info);
    UFUNCTION(BlueprintCallable, NetMulticast, Reliable)
    void All_TeleportDrone(FVector Location, FRotator Rotation);
    // Fix for true pure virtual functions not being implemented
};
