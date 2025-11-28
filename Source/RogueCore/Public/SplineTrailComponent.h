#pragma once
#include "CoreMinimal.h"
#include "Components/SplineMeshComponent.h"
#include "UObject/NoExportTypes.h"
#include "UObject/UnrealType.h"
#include "Curves/CurveFloat.h"
#include "Components/SceneComponent.h"
#include "SplineTrailMaterial.h"
#include "SplineTrailComponent.generated.h"

class UCapsuleComponent;
class UFSDPhysicalMaterial;
class USplineComponent;
class USplineMeshComponent;
class UStaticMesh;
UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class ROGUECORE_API USplineTrailComponent : public USceneComponent {
    GENERATED_BODY()
    

public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSoftObjectPtr<UStaticMesh> StaticMesh;
    
    TArray<FSplineTrailMaterial> MaterialSettings;
    TEnumAsByte<ESplineMeshAxis::Type> ForwardAxis;
    TSoftObjectPtr<UFSDPhysicalMaterial> CollisionMaterial;
    float CollisionCapsuleRadius;
    float TrailLength;
    int32 TrailSubSegments;
    float TrailSegmentOverlap;
    FVector2D Scale;
    float VerticalOffset;
    float HeadBobbingLength;
    float HeadBobbingSpeed;
    FRuntimeFloatCurve ScaleCurve;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, Transient, meta=(AllowPrivateAccess=true))
    TArray<UCapsuleComponent*> CapsuleColliders;
    UPROPERTY(BlueprintReadWrite, DuplicateTransient, EditAnywhere, Instanced, Transient, meta=(AllowPrivateAccess=true))
    USplineComponent* Spline;
    TArray<USplineMeshComponent*> MeshComponents;
    UPROPERTY(BlueprintReadWrite, DuplicateTransient, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TArray<FVector> LocationHistory;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Replicated, meta=(AllowPrivateAccess=true))
    int32 Seed;
    USplineTrailComponent(const FObjectInitializer& ObjectInitializer);
    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
};
