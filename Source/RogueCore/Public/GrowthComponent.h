#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Curves/CurveFloat.h"
#include "GrowthComponent.generated.h"

class USceneComponent;
UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class UGrowthComponent : public UActorComponent {
    GENERATED_BODY()
    // UPROPERTY fields moved from private section

public:
 
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, Transient, meta=(AllowPrivateAccess=true))
    USceneComponent* ScaleComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    FRuntimeFloatCurve CurrentGrowthCurve;
    UGrowthComponent(const FObjectInitializer& ObjectInitializer);
    UFUNCTION(BlueprintCallable)
    void StopGrow();
    void StartGrow(USceneComponent* aComponentToScale, FRuntimeFloatCurve aCurve);
};
