#pragma once
#include "CoreMinimal.h"
#include "Components/StaticMeshComponent.h"
#include "CarveOptionsCellSize.h"
#include "ECarveFilterType.h"
#include "EPreciousMaterialOptions.h"
#include "MeshCarverComponent.generated.h"

class UTerrainMaterialBase;
UCLASS(Blueprintable, EditInlineNew, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class UMeshCarverComponent : public UStaticMeshComponent {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UTerrainMaterialBase* TerrainMaterial;
    
    ECarveFilterType Filter;
    float ExpensiveNoise;
    CarveOptionsCellSize CarverSize;
    EPreciousMaterialOptions PreciousMaterialAction;
    UMeshCarverComponent(const FObjectInitializer& ObjectInitializer);
    UFUNCTION(BlueprintCallable)
    void Carve();
};
