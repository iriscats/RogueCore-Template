#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "FSDMath.generated.h"

class AActor;
UCLASS(Blueprintable)
class UFSDMath : public UBlueprintFunctionLibrary {
    GENERATED_BODY()
public:
    UFSDMath();
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static FVector SphericalToCartesian(float Radius, float Azimuth, float elecation);
    
    UFUNCTION(BlueprintCallable)
    static float SignedAngleBetweenVectors(const FVector& v1, const FVector& v2, const FVector& vAxis);
    static float RoundToDecimalPlace(float Number, int32 decimalPlaces);
    static void RotateActorAroundOffset(AActor* Actor, FVector localSpaceOffset, FRotator Rotator);
    static bool PercentageCheck(float percentage);
    static void GetAzimuthAndElevation(const FVector& Direction, const FTransform& CoordinateSystem, float& Azimuth, float& Elevation);
    static float CubicSegmentLength(FVector p0, FVector tangent1, FVector P1, FVector tangent2);
    static FVector CubicInterpBlueprint(FVector p0, FVector tangent1, FVector P1, FVector tangent2, float alpha);
    static FVector ClampVectorToCone(FVector ToConstrain, FVector ConeDirection, float ConeAngle);
    static void CartesianToSpherical(FVector Location, float& outAzimuth, float& outElevation, float& OutRadius);
    static float AngleBetweenDirections(const FVector& v1, const FVector& v2);
};
