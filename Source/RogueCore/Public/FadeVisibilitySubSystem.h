#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Curves/CurveFloat.h"
#include "Subsystems/WorldSubsystem.h"
#include "FadeVisibilitySubSystem.generated.h"

class ULightComponent;
class UMeshComponent;
class UPrimitiveComponent;
UCLASS(Blueprintable)
class UFadeVisibilitySubSystem : public UWorldSubsystem {
    GENERATED_BODY()
public:
    UFadeVisibilitySubSystem();
    UFUNCTION(BlueprintCallable)
    static void ScalePrimitive(UPrimitiveComponent*& Component, FVector StartScale, FVector EndScale, float Duration);

    static void ScaleOutPrimitive(UPrimitiveComponent*& Component, float Duration);
    static void ScaleInPrimitive(UPrimitiveComponent*& Component, float Duration);
    static void FadeOutMaterialByName(UMeshComponent*& Component, FName Name, FName ParameterName, float Duration);
    static void FadeOutMaterialByIndex(UMeshComponent*& Component, int32 MaterialIndex, FName ParameterName, float Duration);
    static void FadeOutLight(ULightComponent*& Light, float Duration);
    static void FadeLightToIntensity(ULightComponent* Light, float Duration, float endIntensity);
    static void FadeLightByCurve(ULightComponent*& Light, UPARAM(Ref) FRuntimeFloatCurve& Curve);
    static void FadeInMaterialByName(UMeshComponent*& Component, FName Name, FName ParameterName, float Duration);
    static void FadeInMaterialByIndex(UMeshComponent*& Component, int32 MaterialIndex, FName ParameterName, float Duration);
    static void FadeInLight(ULightComponent*& Light, float Duration);
};
