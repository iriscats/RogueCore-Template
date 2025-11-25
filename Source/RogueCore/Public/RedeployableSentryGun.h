#pragma once
#include "CoreMinimal.h"
#include "ERedeployableSentryGunState.h"
#include "SentryGun.h"
#include "Templates/SubclassOf.h"
#include "RedeployableSentryGun.generated.h"

class AActor;
class APlayerCharacter;
class ARedeployableSentryGun;
class ASentryElectroBeam;
class UActorTrackingComponent;
class UOutlineComponent;
class USkeletalMeshComponent;
UCLASS(Abstract, Blueprintable, NoExport)
class ARedeployableSentryGun : public ASentryGun {
    GENERATED_BODY()
    // UPROPERTY fields moved from protected section

public:
    DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnStateChanged, ARedeployableSentryGun*, Sender, ERedeployableSentryGunState, NewState);
    DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnDismantleFinished);
    DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnDestructionRequested, ARedeployableSentryGun*, Sender);
    DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnDeployProgress, float, Progress);
    DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnDeployFinished);
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOnStateChanged OnStateChanged;
    FOnDeployFinished OnDeployFinished;
    FOnDismantleFinished OnDismantleFinished;
    UPROPERTY(BlueprintAssignable, BlueprintCallable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOnDeployProgress OnDeployProgressEvent;
    FOnDestructionRequested OnDestructionRequested;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UActorTrackingComponent* ActorTrackingIcon;
    UOutlineComponent* Outline;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, ReplicatedUsing=OnRep_SentryGunOwner, meta=(AllowPrivateAccess=true))
    TWeakObjectPtr<APlayerCharacter> SentryGunOwner;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bOutlineAndIconVisible;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, ReplicatedUsing=OnRep_State, meta=(AllowPrivateAccess=true))
    ERedeployableSentryGunState State;
    float PlasmaLineMaxRange;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TArray<ASentryElectroBeam*> PlasmaLines;
    TSubclassOf<ASentryElectroBeam> PlasmaBeamClass;
    TSubclassOf<AActor> ElectrocutionActorClass;
    AActor* ElectrocutionActor;
    TSubclassOf<AActor> EMPDischargeActorClass;
    float EMPDiscargeCooldown;
    ARedeployableSentryGun(const FObjectInitializer& ObjectInitializer);
    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
    UFUNCTION(BlueprintCallable)
    void ToggleOutlineAndIcon(bool visible);
    void SetSentryGunOwner(APlayerCharacter* Character);
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void ReceiveOnStateChanged();
    void ReceiveOnSentryGunOwnerChanged();
    void ReceiveOnDismantled();
    void ReceiveOnDismantle();
    void ReceiveOnDeployed();
    void ReceiveOnDeploy();
    UFUNCTION()
    void OnRep_State(ERedeployableSentryGunState oldState);
    UFUNCTION()
    void OnRep_SentryGunOwner();
    void OnElectrocutionActorDestroyed(AActor* Actor);
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool GetIsDismantled() const;
    bool GetIsDeployed() const;
    float GetAnimDuration(USkeletalMeshComponent* mesh);
    UFUNCTION(BlueprintAuthorityOnly, BlueprintCallable)
    void DismantleFinished();
    void Dismantle();
    void DeployFinished();
    void Deploy();
    UFUNCTION(BlueprintAuthorityOnly, BlueprintCallable, BlueprintImplementableEvent)
    void ActivateSpecialAttack();
};
