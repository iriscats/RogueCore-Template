#pragma once
#include "CoreMinimal.h"
#include "Components/PrimitiveComponent.h"
#include "CSGOptions.h"
#include "CarveOptionsCellSize.h"
#include "ECarveFilterType.h"
#include "EDebrisItemPass.h"
#include "Templates/SubclassOf.h"
#include "LevelGenerationCarverComponent.generated.h"

class ACSGBuilder;
class USTLMeshCarver;
class UStaticMesh;
class UStaticMeshCarver;
class UTerrainMaterialBase;
class UTerrainType;
UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class ULevelGenerationCarverComponent : public UPrimitiveComponent {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool UseCarveInPass;
    
    EDebrisItemPass CarveInPass;
    USTLMeshCarver* MeshCarver;
    UStaticMesh* ConvexCarver;
    UStaticMeshCarver* StaticMeshCarver;
    TSubclassOf<ACSGBuilder> CSGCarver;
    FCSGOptions CSGCarverSettings;
    UTerrainType* TerrainType;
    UTerrainMaterialBase* TerrainMaterial;
    ECarveFilterType Filter;
    float ConvexExpensiveNoise;
    CarveOptionsCellSize CarveCellSize;
    bool PreviewEnabled;
    bool CarvingDisabled;
protected:
    bool SelfActivate;
    ULevelGenerationCarverComponent(const FObjectInitializer& ObjectInitializer);
    UFUNCTION(BlueprintCallable)
    void AddCarverComponentToProceduralSetup();
};
