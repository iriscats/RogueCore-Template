#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "UObject/UnrealType.h"
#include "EInputKeys.h"
#include "EPipelineBuildState.h"
#include "TrackBuilderSegment.h"
#include "PipelineSegment.generated.h"

class APipelineSegment;
class APipelineStart;
class APlayerCharacter;
class UDroneUseComponent;
class UHealthComponentBase;
class UMaterialInterface;
class UPathfinderSplineSegmentCollisionComponent;
class USimpleHealthComponent;
class USingleUsableComponent;
class USkeletalMeshComponent;
class USplineComponent;
class USplineMeshComponent;
class UStaticMesh;
class UStaticMeshComponent;
class UTrackBuilderUsable;
UCLASS(Abstract, Blueprintable)
class APipelineSegment : public ATrackBuilderSegment {
    GENERATED_BODY()
    // UPROPERTY fields moved from protected section

public:
    DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FPipelineStateDelegate, EPipelineBuildState, InPipelineState);
    DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FPipelineSegmentDelegate, APipelineSegment*, InPipelineSegment);
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FPipelineSegmentDelegate OnPipelineBroken;
    FPipelineSegmentDelegate OnPipelineRepaired;
    FPipelineSegmentDelegate OnPipelineActivated;
    FPipelineStateDelegate OnPipelineStateChanged;
 
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UStaticMesh* StaticMeshUnassembled;
    UStaticMesh* StaticMeshAssembled;
    UStaticMesh* StaticMeshFinal;
    FVector EditorEndLocation;
    TEnumAsByte<ETraceTypeQuery> CarvingTraceType;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    UMaterialInterface* NumberMaterial;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    USingleUsableComponent* RepairSegmentUsable;
    USingleUsableComponent* ActivateSegmentUsable;
    UDroneUseComponent* DroneUsable;
    USimpleHealthComponent* SegmentHealthComponent;
    USplineComponent* MovementSpline;
    USplineComponent* MovementSplineRight;
    USplineComponent* MovementSplineLeft;
    USplineMeshComponent* PipelineMesh;
    USplineMeshComponent* PipelineOuterMesh;
    USkeletalMeshComponent* PipelineCapMesh;
    USkeletalMeshComponent* EndPostMesh;
    UStaticMeshComponent* EndPostMeshStatic;
    UPathfinderSplineSegmentCollisionComponent* PathfinderComponent;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, ReplicatedUsing=OnRep_SegmentBroken, meta=(AllowPrivateAccess=true))
    bool bSegmentBroken;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, ReplicatedUsing=OnRep_SegmentActivatedProgress, meta=(AllowPrivateAccess=true))
    float SegmentActivatedProgress;
    EPipelineBuildState PipelineState;
    TWeakObjectPtr<APipelineStart> PipelineStart;
    float MinValidLength;
    float MaxValidLength;
    float TooSharpExtraLength;
    float TooSteepExtraLength;
    float BlockedSphereSize;
    int32 BlockedExtraRaytraceRotationOffset;
    float BlockedExtraRaytraces;
    float BlockedExtraRaytraceDist;
    float BlockedRayTraceSuccesses;
    APipelineSegment(const FObjectInitializer& ObjectInitializer);
    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
    UFUNCTION(BlueprintCallable)
    void UpdateSplineMesh(USplineMeshComponent* InMesh, float InProgress, bool InMoveEndCap);
    UFUNCTION(BlueprintAuthorityOnly, BlueprintCallable)
    void SetSegmentBroken(APlayerCharacter* InUser, bool InSegmentBroken);
    void SetPipelineNumberMaterial(UMaterialInterface* InNumberMaterial);
    void SetEndPostVisible(bool inVisible);
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void ReceiveSegmentBrokenChanged(bool InSegmentBroken);
    void ReceiveSegmentActivatedProgress(float InProgress);
    void ReceiveSegmentActivated();
    void ReceivePlacementFinished();
    void ReceivePlacementBegin();
    void OnRepaired(APlayerCharacter* InUser);
    UFUNCTION()
    void OnRep_SegmentBroken();
    UFUNCTION()
    void OnRep_SegmentActivatedProgress();
    UFUNCTION(BlueprintCallable, BlueprintPure)
    APipelineStart* GetPipelineStart() const;
    APipelineSegment* GetNextPipelineSegment(bool bForward) const;
    bool GetIsSegmentActivated() const;
    void CallbackSegmentRepaired(APlayerCharacter* InUser, EInputKeys Key);
    void CallbackSegmentDestroyed(UHealthComponentBase* InHealth);
    void CallbackSegmentActivatedProgress(float InProgress);
    void CallbackSegmentActivated(APlayerCharacter* InUser, EInputKeys Key);
    void CallbackPipelineStateChanged(APipelineStart* InPipelineStart, EPipelineBuildState InState);
    void CallbackNextSegmentChanged(UTrackBuilderUsable* InUsable, ATrackBuilderSegment* InSegment);
    void CallbackDroneUsed(int32 timesUsed);
};
