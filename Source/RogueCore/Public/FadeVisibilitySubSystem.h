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
    static void ScalePrimitive(const UPrimitiveComponent*& Component, FVector StartScale, FVector EndScale, float Duration);
    
    static void ScaleOutPrimitive(const UPrimitiveComponent*& Component, float Duration);
    static void ScaleInPrimitive(const UPrimitiveComponent*& Component, float Duration);
    static void FadeOutMaterialByName(const UMeshComponent*& Component, FName Name, FName ParameterName, float Duration);
    static void FadeOutMaterialByIndex(const UMeshComponent*& Component, int32 MaterialIndex, FName ParameterName, float Duration);
    static void FadeOutLight(const ULightComponent*& Light, float Duration);
    static void FadeLightToIntensity(ULightComponent* Light, float Duration, float endIntensity);
    static void FadeLightByCurve(const ULightComponent*& Light, UPARAM(Ref) FRuntimeFloatCurve& Curve);
    static void FadeInMaterialByName(const UMeshComponent*& Component, FName Name, FName ParameterName, float Duration);
    static void FadeInMaterialByIndex(const UMeshComponent*& Component, int32 MaterialIndex, FName ParameterName, float Duration);
    static void FadeInLight(const ULightComponent*& Light, float Duration);
};
