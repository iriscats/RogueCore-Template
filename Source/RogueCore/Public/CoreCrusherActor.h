#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "GameFramework/Actor.h"
#include "DelegateEventDelegate.h"
#include "ECoreCrusherState.h"
#include "EInputKeys.h"
#include "CoreCrusherActor.generated.h"

class APlayerCharacter;
class UFriendlyHealthComponent;
class UHealthComponentBase;
class UPathfinderCollisionComponent;
class URepairableComponent;
class URepairableUsable;
class USceneComponent;
class USingleUsableComponent;
class USkeletalMeshComponent;
UCLASS(Blueprintable, NoExport)
class ROGUECORE_API ACoreCrusherActor : public AActor {
    GENERATED_BODY()
    // UPROPERTY fields moved from protected section

public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    USceneComponent* Root;
    
    USkeletalMeshComponent* CoreCrusherMesh;
    UPathfinderCollisionComponent* PathfinderCollision;
    URepairableUsable* RepairableUsable;
    UFriendlyHealthComponent* FriendlyHealth;
    USingleUsableComponent* RevivableUsable;
    USingleUsableComponent* RunningRepairUsable;
    USceneComponent* UsableCollider;
    URepairableComponent* Repairable;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FVector2D BreakdownTimeRange;
    float InitialBootTime;
    float RebootTime;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, ReplicatedUsing=OnRep_State, meta=(AllowPrivateAccess=true))
    ECoreCrusherState State;
    float HealPerUse;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Replicated, meta=(AllowPrivateAccess=true))
    float CurrentBootLeft;
protected:
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FDelegateEvent OnPartInserted;
    void RepairableUsableOnUsedBy(APlayerCharacter* User, EInputKeys Key);
    void ReceiveStateChange(ECoreCrusherState InState);
    void OnRunningRepairUsedBy(APlayerCharacter* User, EInputKeys Key);
    void OnRevivableUsedBy(APlayerCharacter* User, EInputKeys Key);
    UFUNCTION()
    void OnRep_State();
    void OnDeath(UHealthComponentBase* HealthComponent);
    void OnDamage(float amount);
    void OnAllResourcesAcquiredEvent(URepairableComponent* Component);
};