#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Curves/CurveFloat.h"
#include "ImpactIndicator.generated.h"

class USceneComponent;
UCLASS(Blueprintable, NoExport)
class AImpactIndicator : public AActor {
    GENERATED_BODY()
    // UPROPERTY fields moved from protected section

public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    USceneComponent* Root;
    
    USceneComponent* InnerScaler;
    USceneComponent* OuterScaler;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FRuntimeFloatCurve OuterGrowthCurve;
    FRuntimeFloatCurve InnerGrowthCurve;
    float Radius;
    AImpactIndicator(const FObjectInitializer& ObjectInitializer);
    UFUNCTION(BlueprintCallable)
    void SetRadius(float NewRadius);
};
