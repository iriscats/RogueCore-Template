#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Curves/CurveFloat.h"
#include "LightModulationComponent.generated.h"

class UMaterialInstanceDynamic;
class UPointLightComponent;
UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class ULightModulationComponent : public UActorComponent {
    GENERATED_BODY()
    // UPROPERTY fields moved from protected section

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))

    FRuntimeFloatCurve ModulationCurve;

    

    float PhotoSensitiveMaterialModifier;

    float PhotoSensitiveLightModifier;

    bool Loop;

    bool AffectedByPhotosensitivity;

    bool RandomStartTime;

    ULightModulationComponent(const FObjectInitializer& ObjectInitializer);

    UFUNCTION(BlueprintCallable)

    void StopModulation();



public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FRuntimeFloatCurve ModulationCurve;
    
    float PhotoSensitiveMaterialModifier;
    float PhotoSensitiveLightModifier;
    bool Loop;
    bool AffectedByPhotosensitivity;
    bool RandomStartTime;
    ULightModulationComponent(const FObjectInitializer& ObjectInitializer);
    UFUNCTION(BlueprintCallable)
    void StopModulation();
    void StartModulation();
    void SetLightCount(int32 lightCount);
    void AddMaterial(UMaterialInstanceDynamic* Material, const FName& Param, float MaxIntensity);
    void AddLight(UPointLightComponent* Light, float MaxIntensity);
};
