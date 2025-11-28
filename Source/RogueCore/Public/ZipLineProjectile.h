#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "GameFramework/Actor.h"
#include "Components/TimelineComponent.h"
#include "Templates/SubclassOf.h"
#include "ZipLineProjectile.generated.h"

class UCurveFloat;
class UMaterialInstanceDynamic;
class UPointLightComponent;
class UStatusEffect;
class UTimelineComponent;
UCLASS(Abstract, Blueprintable)
class AZipLineProjectile : public AActor {
    GENERATED_BODY()
    

public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UTimelineComponent* Timeline;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float LightIntensity;
    float MaterialGlow;
    FOnTimelineFloat Callback;
    UCurveFloat* LightCurve;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, Transient, meta=(AllowPrivateAccess=true))
    TArray<UPointLightComponent*> PointLights;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TArray<UMaterialInstanceDynamic*> MaterialInstances;
    TSubclassOf<UStatusEffect> OnUseStatusEffect;
    TSubclassOf<UStatusEffect> OnReleaseStatusEffect;
    AZipLineProjectile(const FObjectInitializer& ObjectInitializer);
    UFUNCTION(BlueprintCallable)
    void OnTimelineTick(float NewValue);
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnShoot(FVector Origin, FVector EndLocation);
};
