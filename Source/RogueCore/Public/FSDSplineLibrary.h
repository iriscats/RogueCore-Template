#pragma once
#include "CoreMinimal.h"
#include "UObject/UnrealType.h"

#include "Kismet/BlueprintFunctionLibrary.h"
#include "Components/SplineComponent.h"

#include "ECarveFilterType.h"
#include "EPreciousMaterialOptions.h"
#include "Blueprint/UserWidget.h"
#include "Curve2DAppearance.h"
#include "FSDSplineLibrary.generated.h"

class AActor;
class UObject;
class USplineComponent;
class USplineMeshComponent;
class UTerrainMaterial;
UCLASS(Blueprintable)
class UFSDSplineLibrary : public UBlueprintFunctionLibrary {
    GENERATED_BODY()
public:
    UFSDSplineLibrary();
    UFUNCTION(BlueprintCallable)
    static bool SplineComponentSphereTrace(const USplineComponent* SplineComponent, float Radius, TEnumAsByte<ETraceTypeQuery> TraceType, float StepSize, TArray<AActor*> IgnoreActors, FHitResult& OutHitResult, FVector Offset);
    
    static void SetStartAndEndTangentsCurve2D(UPARAM(Ref) FInterpCurveVector2D& Curve, FVector2D StartTangent, FVector2D EndTangent);
    static TArray<FTransform> GetSplineComponentTransforms(const USplineComponent* SplineComponent, float StepSize, TEnumAsByte<ESplineCoordinateSpace::Type> Space);
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static void GetLocationAndTangentsAtSplinePoint(const USplineComponent* Spline, int32 PointIndex, FVector& Location, FVector& ArriveTangent, FVector& LeaveTangent, TEnumAsByte<ESplineCoordinateSpace::Type> CoordinateSpace);
    static void EvalCurveScaled2D(const FInterpCurveVector2D& Curve, float Key, FVector2D ScaleBy, FVector2D& OutPosition, FVector2D& OutTangent);
    static void EvalCurve2D(const FInterpCurveVector2D& Curve, float Key, FVector2D& OutPosition, FVector2D& OutTangent);
    static void DrawCurveScaled2D(UPARAM(Ref) FPaintContext& Context, const FInterpCurveVector2D& Curve, FVector2D ScaleBy, FCurve2DAppearance Appearance, float Opacity);
    static void DrawCurve2D(UPARAM(Ref) FPaintContext& Context, const FInterpCurveVector2D& Curve, FCurve2DAppearance Appearance, float Opacity);
    static void DrawBezierScaled2D(UPARAM(Ref) FPaintContext& Context, FVector2D InStartPos, FVector2D InStartTangent, FVector2D InEndPos, FVector2D InEndTangent, FCurve2DAppearance InAppearance, FVector2D ScaleBy, float Opacity, bool InClampTangents);
    static void DrawBezier2D(UPARAM(Ref) FPaintContext& Context, FVector2D InStartPos, FVector2D InStartTangent, FVector2D InEndPos, FVector2D InEndTangent, FCurve2DAppearance InAppearance, float Opacity, bool InClampTangents);
    static FInterpCurveVector2D CreateCurveWithTangents2D(const TArray<FVector2D>& Positions, FVector2D StartTangent, FVector2D EndTangent, TEnumAsByte<EInterpCurveMode> Mode);
    static FInterpCurveVector2D CreateCurve2D(const TArray<FVector2D>& Positions, TEnumAsByte<EInterpCurveMode> Mode);
    static void ConvertSplineDistanceToInputKey(UPARAM(Ref) USplineComponent*& SplineComponent, USplineComponent* OptionalTargetSpline);
    UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContext"))
    static bool CarveAroundSplinePoints(UObject* WorldContext, const FVector& InStartLocation, const FVector& InStartTangent, const FVector& InEndLocation, const FVector& InEndTangent, float InRadius, UTerrainMaterial* InTerrainMaterial, ECarveFilterType InCarveFilter, EPreciousMaterialOptions InPrecious);
    static bool CarveAroundSplineMesh(USplineMeshComponent* InMesh, float InRadius, UTerrainMaterial* InTerrainMaterial, ECarveFilterType InCarveFilter, EPreciousMaterialOptions InPrecious);
    static float ApproximateSplineDistanceAtWorldLocation(const USplineComponent* Spline, const FVector& WorldLocation);
};
