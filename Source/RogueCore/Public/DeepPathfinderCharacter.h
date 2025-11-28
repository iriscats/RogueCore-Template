#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "VisualLogger/VisualLoggerDebugSnapshotInterface.h"
#include "FSDPawn.h"
#include "StaggerParams.h"
#include "TriggerAI.h"
#include "DeepPathfinderCharacter.generated.h"

class UAIPlayerControlComponent;
class UDeepPatherFinderCharacterAfflictionComponent;
class UDeepPathfinderMovement;
class UMaterialInterface;
class UObject;
class UPawnAffliction;
class USkeletalMeshComponent;
UCLASS(Blueprintable)
class ADeepPathfinderCharacter : public AFSDPawn, public ITriggerAI, public IVisualLoggerDebugSnapshotInterface {
    GENERATED_BODY()
    

public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UDeepPathfinderMovement* PathfinderMovement;

    USkeletalMeshComponent* mesh;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName CenterMassSocketName;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    float AnimationOffset;
    UPROPERTY(EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    int8 MeshDecalIndex;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, Transient, meta=(AllowPrivateAccess=true))
    UAIPlayerControlComponent* AIPlayerControlComponentCache;

 
    UDeepPatherFinderCharacterAfflictionComponent* Affliction;
    bool CanPlayerStandOn;
    bool UseDormancy;
    float StaggerDurationMultiplier;
    float StaggerImunityWindow;
    TSet<UObject*> InStaggerImmunitySources;
    bool StaggerPauseLogic;
    bool IsHidden;
    bool IsStaggered;
    bool FrozenPauseLogic;
    UPawnAffliction* CurrentStaggerAffliction;
    float AttackerRadius;
    TArray<UMaterialInterface*> CachedMaterials;
    float AllowedInFormationChance;
    ADeepPathfinderCharacter(const FObjectInitializer& ObjectInitializer);
    UFUNCTION(BlueprintCallable)
    bool TryJoinFormation();
    void Stagger(const FStaggerParams& StaggerParams);
    void SetStaggerImmunity(bool InImmune, const UObject* InStaggerImmunitySource);
    void SetHidden(bool shouldHide);
    void OnPausedMovementElapsed();
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnControlledByPlayer(bool IsControlled, bool IsLocallyControlled);
    UFUNCTION(BlueprintCallable, NetMulticast, Reliable)
    void Multicast_SetActorRotation(const FRotator& Rotator);
    void LeaveFormation();
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool GetCanStagger() const;
    // Fix for true pure virtual functions not being implemented
};
