#pragma once
#include "CoreMinimal.h"

#include "TrackBuilderSegment.h"
#include "FuelLineSegment.generated.h"

class UHealthComponentBase;
class USceneComponent;
class USimpleHealthComponent;
class USplineComponent;
class USplineMeshComponent;
class UStaticMeshComponent;
UCLASS(Abstract, Blueprintable)
class ROGUECORE_API AFuelLineSegment : public ATrackBuilderSegment {
    GENERATED_BODY()
    // UPROPERTY fields moved from private section
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    USplineMeshComponent* FuelLineSplineMesh;
    
    USplineComponent* FuelLineSplineComponent;
    UStaticMeshComponent* FuelLineEndPostMesh;
    USimpleHealthComponent* DeconstructHealthComponent;
    USceneComponent* PreviewEndPostLocation;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float EndPostHeightOffset;
    float MaxLength;
    bool bHasMaxTurnAngle;
    float MaxTurnAngle;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    bool bHaveFlowingLiquid;
    AFuelLineSegment(const FObjectInitializer& ObjectInitializer);
    UFUNCTION(BlueprintCallable)
    void SetHaveFlowingLiquid(const bool NewHaveFlowingLiquid);
    void PropagateFlowingLiquid(const bool NewHaveFlowingLiquid);
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool HaveFlowingLiquid() const;

    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnFlowingLiquidChanged();
    UFUNCTION(BlueprintCallable, Client, Unreliable)
    void ClientUpdateStartTransform(const FVector& NewStartLocation);
    void ChangeStartTransform(const FTransform& ChangedStartLocation);
    void CallbackOnDeath(UHealthComponentBase* InHealthComponent);
    void CallbackCanStartNextSegmentChanged(bool InCanStart);
};
