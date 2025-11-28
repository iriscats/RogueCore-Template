#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Components/InstancedStaticMeshComponent.h"
#include "SplineDecoratorComponent.generated.h"

class UMaterialInterface;
class USplineComponent;
UCLASS(Blueprintable, EditInlineNew, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class ROGUECORE_API USplineDecoratorComponent : public UInstancedStaticMeshComponent {
    GENERATED_BODY()
    
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float DistanceBetweenInstances;
    
    int32 StartIndex;
    int32 EndIndex;
    bool bUpdateContinuously;
    FVector VerticalOffset;
    FVector Scale;
    float DistanceProgress;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, Transient, meta=(AllowPrivateAccess=true))
    USplineComponent* SplineComponent;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TArray<FTransform> NewInstancesTransforms;
    float Phase;
    USplineDecoratorComponent(const FObjectInitializer& ObjectInitializer);
    UFUNCTION(BlueprintCallable)
    void Update(float DeltaTime);
    void SetUpdateContinuously(bool InContinuously);
    void SetSplineComponentAndMaterial(USplineComponent* InSplineComponent, int32 ElementIndex, UMaterialInterface* Material);
    void SetSplineComponent(USplineComponent* InSplineComponent);
};
