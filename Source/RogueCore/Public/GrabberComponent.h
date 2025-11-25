#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "GameplayTagContainer.h"
#include "EGrabbedStateCameraMode.h"
#include "EOutline.h"
#include "GrabbedActorSigDelegate.h"
#include "ReleasedActorSigDelegate.h"
#include "GrabberComponent.generated.h"

class AActor;
class ADeepPathfinderCharacter;
class UAudioComponent;
class UDialogDataAsset;
class UPrimitiveComponent;
class USkeletalMeshComponent;
class USoundCue;
UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class UGrabberComponent : public UActorComponent {
    GENERATED_BODY()
    // UPROPERTY fields moved from protected section

public:
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGrabbedActorSig OnGrabbedActor;
    
    FReleasedActorSig OnReleasedActor;
 
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGameplayTagQuery TagFilter;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, Transient, meta=(AllowPrivateAccess=true))
    UAudioComponent* GrabLoopSoundInstance;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TWeakObjectPtr<ADeepPathfinderCharacter> PathfinderOwner;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Export, Transient, meta=(AllowPrivateAccess=true))
    TWeakObjectPtr<USkeletalMeshComponent> OwnerMesh;
    USoundCue* BeginGrabedSound;
    USoundCue* GrabedLoopSound;
    USoundCue* EndGrabedSound;
    UDialogDataAsset* BeginGrabbedShout;
    UDialogDataAsset* EndGrabbedShout;
    UDialogDataAsset* AttentionGrabbedShout;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, ReplicatedUsing=OnRep_CurrentlyGrabbed, meta=(AllowPrivateAccess=true))
    AActor* CurrentlyGrabbed;
    FName GrabAttachName;
    float GrabTime;
    float CarryCooldown;
    float RevivedGravePeriod;
    EOutline PlayerOutlineOnGrab;
    EGrabbedStateCameraMode CameraMode;
    bool TrackPlayerCollision;
    bool ManualGrabTime;
    bool CanPlayerShoot;
    bool HeightenSensesImmune;
    bool NeedsPathToTarget;
    UGrabberComponent(const FObjectInitializer& ObjectInitializer);
    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
    UFUNCTION(BlueprintCallable)
    void Timer_ReleaseTarget();
    UFUNCTION(BlueprintAuthorityOnly, BlueprintCallable)
    void ReleaseTarget();
    UFUNCTION()
    void OnRep_CurrentlyGrabbed(AActor* oldCurrentlyGrabbed);
    void OnPrimWake(UPrimitiveComponent* WakingComponent, FName BoneName);
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsGrabbedTargetValid() const;
    bool HasGrabbed() const;
    bool GrabTarget(AActor* aGrabTarget);
    AActor* GetGrabbedActor();
    bool CanGrabTarget(AActor* aTarget, const bool AllowDowned) const;
};
