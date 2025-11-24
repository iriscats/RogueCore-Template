#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "GlowPlant.generated.h"

class UPointLightComponent;
class UPrimitiveComponent;
class UStaticMeshComponent;
UCLASS(Abstract, Blueprintable, NoExport)
class AGlowPlant : public AActor {
    GENERATED_BODY()
    // UPROPERTY fields moved from protected section

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))

    float IntensityBase;

    float RadiusBase;

    float IntensityPerPart;

    float RadiusPerPart;

    float IntensityAllParts;

    float RadiusAllParts;

    float MaxIntensity;

    float MinIntensity;

    float TimeOnMaxLight;

    float IntensityFadeInTime;

    float IntensityFadeOutTime;

    float MaxEmissive;

    float MinEmissive;

    float EmissiveFadeInTime;

    float EmissiveFadeOutTime;

    AGlowPlant(const FObjectInitializer& ObjectInitializer);



public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UStaticMeshComponent* TrunkMesh;
    
protected:
    UPointLightComponent* mainLight;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float IntensityBase;
    float RadiusBase;
    float IntensityPerPart;
    float RadiusPerPart;
    float IntensityAllParts;
    float RadiusAllParts;
    float MaxIntensity;
    float MinIntensity;
    float TimeOnMaxLight;
    float IntensityFadeInTime;
    float IntensityFadeOutTime;
    float MaxEmissive;
    float MinEmissive;
    float EmissiveFadeInTime;
    float EmissiveFadeOutTime;
    AGlowPlant(const FObjectInitializer& ObjectInitializer);
    UFUNCTION(BlueprintCallable, NetMulticast, Reliable)
    void OnDeath();
    UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
    void OnDamage(UPrimitiveComponent* hitSphere);
};
