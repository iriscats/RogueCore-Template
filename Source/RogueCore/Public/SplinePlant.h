#pragma once
#include "CoreMinimal.h"
#include "Components/SplineMeshComponent.h"
#include "UObject/NoExportTypes.h"
#include "GameFramework/Actor.h"
#include "UObject/UnrealType.h"
#include "Curves/CurveFloat.h"
#include "SplinePlant.generated.h"

class UAudioComponent;
class USceneComponent;
class USoundCue;
class USplineComponent;
class USplineMeshComponent;
class UStaticMesh;
UCLASS(Blueprintable, NoExport)
class ROGUECORE_API ASplinePlant : public AActor {
    GENERATED_BODY()
    // UPROPERTY fields moved from protected section

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Replicated, meta=(AllowPrivateAccess=true))

    int32 Seed;

    ASplinePlant(const FObjectInitializer& ObjectInitializer);



public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    USplineComponent* PlantSpline;
    
    USceneComponent* PlantEndPoint;
    UAudioComponent* AudioComponent;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSoftObjectPtr<USoundCue> CueExtending;
    TSoftObjectPtr<USoundCue> CueRetracting;
    USoundCue* AudioExtending;
    USoundCue* AudioRetracting;
    bool bEnabledSegmentCollision;
    float CarveRadius;
    TSoftObjectPtr<UStaticMesh> SegmentMeshPtr;
    TEnumAsByte<ESplineMeshAxis::Type> SegmentForwardAxis;
    float SegmentLength;
    FRuntimeFloatCurve SegmentWidthCurve;
    float SegmentWidthScale;
    FRuntimeFloatCurve SegmentHeightCurve;
    float SegmentHeightScale;
    float PreviewLengthPercent;
    int32 PreviewSeed;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, Transient, meta=(AllowPrivateAccess=true))
    TArray<USplineMeshComponent*> SegmentMeshCache;
    TArray<USplineMeshComponent*> CollisionMeshCache;
    USplineComponent* SplineInstance;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    UStaticMesh* SegmentMesh;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Replicated, meta=(AllowPrivateAccess=true))
    int32 Seed;
    ASplinePlant(const FObjectInitializer& ObjectInitializer);
    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
    UFUNCTION(BlueprintCallable)
    void SetTargetPlantLengthPercent(float InTargetPercent, float InPercentPerSecond, float InEaseExp);
    void SetTargetPlantLength(float InTargetLength, float InDistancePerSecond, float InEaseExp);
    void SetPlantLengthPercent(float InPercent);
    void ResetSpline();
    void ResetScale();
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void ReceivePrepareSpline(USplineComponent* InSplineComponent, int32 InSeed);
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void ReceiveMovementUpdated(float InDistanceProgress);
    void ReceiveMovementStarted(float InTargetDistance);
    void ReceiveMovementFinished(float InDistanceProgress);
    UFUNCTION(BlueprintCallable, BlueprintPure)
    float GetPlantTargetLengthPercent() const;
    float GetPlantLengthPercent() const;
    FTransform GetNearestLocationToLocalPlayer() const;
    float GetFullPlantLength() const;
};
