#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "DelegateDelegate.h"
#include "EEscortExtractorState.h"
#include "EEscortMissionState.h"
#include "EscortMuleExtractorSlot.h"
#include "EscortMuleMovementState.h"
#include "FSDPawn.h"
#include "FloatDelegateDelegate.h"
#include "GaragePathSignatureDelegate.h"
#include "IntDelegateDelegate.h"
#include "MuleActivatedSignatureDelegate.h"
#include "SpeedChangedSignatureDelegate.h"
#include "TriggerAI.h"
#include "EscortMule.generated.h"

class AExtractorItem;
class APlayerCharacter;
class UEscortObjective;
class UFriendlyHealthComponent;
class UInstantUsable;
class UOutlineComponent;
class URestrictedResourceBank;
class USimpleObjectInfoComponent;
class USkeletalMeshComponent;
UCLASS(Blueprintable, NoExport)
class ROGUECORE_API AEscortMule : public AFSDPawn, public ITriggerAI {
    GENERATED_BODY()
    // UPROPERTY fields moved from protected section

    UPROPERTY(BlueprintReadWrite, EditAnywhere, ReplicatedUsing=OnRep_ExtractorSlots, meta=(AllowPrivateAccess=true))

    TArray<FEscortMuleExtractorSlot> ExtractorSlots;

    AEscortMule(const FObjectInitializer& ObjectInitializer);



public:
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FMuleActivatedSignature OnMuleActivated;
    
    FSpeedChangedSignature OnSpeedChanged;
    FIntDelegate OnFullCanistersChanged;
    FGaragePathSignature OnExitGaragePathSet;
    FFloatDelegate Cheat_SetMuleSpeed;
    FDelegate Cheat_JumpToNextPhase;
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UFriendlyHealthComponent* HealthComponent;
    USimpleObjectInfoComponent* ObjectInfo;
    URestrictedResourceBank* ResourceBank;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    FTransform TargetTransform;
    FTransform PreviousTransform;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, ReplicatedUsing=OnObjectiveStateChanged, meta=(AllowPrivateAccess=true))
    EEscortMissionState State;
    UEscortObjective* EscortObjective;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, ReplicatedUsing=OnRep_MovementState, meta=(AllowPrivateAccess=true))
    FEscortMuleMovementState MovementState;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, ReplicatedUsing=OnRep_SpeedModifier, meta=(AllowPrivateAccess=true))
    float SpeedModifier;
    USkeletalMeshComponent* mesh;
    UOutlineComponent* OutlineComponent;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float HealPerTickNormal;
    float HealPerTickUnderAttack;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Replicated, Transient, meta=(AllowPrivateAccess=true))
    bool CannisterVisible_Left;
    bool CannisterVisible_Right;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Replicated, meta=(AllowPrivateAccess=true))
    FVector NextStop;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, ReplicatedUsing=OnRep_IsCarvingTunnel, meta=(AllowPrivateAccess=true))
    bool IsCarvingTunnel;
    int32 FullCanisters;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, ReplicatedUsing=OnRep_ExtractorSlots, meta=(AllowPrivateAccess=true))
    TArray<FEscortMuleExtractorSlot> ExtractorSlots;
    AEscortMule(const FObjectInitializer& ObjectInitializer);
    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
    UFUNCTION(BlueprintCallable)
    bool TryHeal(APlayerCharacter* User, float amount);
    UFUNCTION(BlueprintAuthorityOnly, BlueprintCallable)
    void SetTargetTransform(FTransform InTransform);
    void SetSpeedModifier(float inSpeedModifier);
    void SetFullExtracterAttached(UInstantUsable* usable);
    void SetExtractorDetached(UInstantUsable* usable);
    void SetExitGaragePath(const TArray<FVector> Path);
    void ResetExtractors();
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void PathIsReady();
    UFUNCTION()
    void OnRep_SpeedModifier();
    UFUNCTION()
    void OnRep_MovementState();
    UFUNCTION()
    void OnRep_IsCarvingTunnel();
    UFUNCTION()
    void OnRep_ExtractorSlots();
    UFUNCTION()
    void OnObjectiveStateChanged(EEscortMissionState oldState);
    void OnExtractorSlotChanged(const FEscortMuleExtractorSlot& Slot, int32 Index);
    void OnExtractorDetached(AExtractorItem* Item);
    void ObjectiveStateChange(EEscortMissionState NewState);
    UFUNCTION(BlueprintCallable, BlueprintPure)
    EEscortExtractorState GetExtractorState(UInstantUsable* usable) const;
    void ActivateMule();
    // Fix for true pure virtual functions not being implemented
};
