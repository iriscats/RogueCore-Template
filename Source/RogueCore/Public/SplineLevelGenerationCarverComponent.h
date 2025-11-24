#pragma once
#include "CoreMinimal.h"
#include "Components/SplineComponent.h"
#include "ECarveFilterType.h"
#include "EDebrisItemPass.h"
#include "SplineLevelGenerationCarverComponent.generated.h"

class UTerrainMaterialBase;
class UTerrainType;
UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class USplineLevelGenerationCarverComponent : public USplineComponent {
    GENERATED_BODY()
    // UPROPERTY fields moved from protected section

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))

    UTerrainType* TerrainType;

    

    UTerrainMaterialBase* TerrainMaterial;

    float CarveRadius;

    float ConvexExpensiveNoise;

    ECarveFilterType Filter;

    EDebrisItemPass CarveInPass;

    bool UseCarveInPass;

    bool SelfActivate;

    bool CarvingDisabled;

    USplineLevelGenerationCarverComponent(const FObjectInitializer& ObjectInitializer);

    UFUNCTION(BlueprintCallable)

    void AddCarverComponentToProceduralSetup();



public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UTerrainType* TerrainType;
    
    UTerrainMaterialBase* TerrainMaterial;
    float CarveRadius;
    float ConvexExpensiveNoise;
    ECarveFilterType Filter;
    EDebrisItemPass CarveInPass;
    bool UseCarveInPass;
    bool SelfActivate;
    bool CarvingDisabled;
    USplineLevelGenerationCarverComponent(const FObjectInitializer& ObjectInitializer);
    UFUNCTION(BlueprintCallable)
    void AddCarverComponentToProceduralSetup();
};
