#pragma once
#include "CoreMinimal.h"
#include "Components/PrimitiveComponent.h"
#include "ECarveFilterType.h"
#include "EPreciousMaterialOptions.h"
#include "STLMeshCarverComponent.generated.h"

class USTLMeshCarver;
class UTerrainMaterialBase;
UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class USTLMeshCarverComponent : public UPrimitiveComponent {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UTerrainMaterialBase* TerrainMaterial;
    
    USTLMeshCarver* MeshCarver;
    ECarveFilterType Filter;
    bool PreviewEnabled;
    EPreciousMaterialOptions PreciousMaterialAction;
    USTLMeshCarverComponent(const FObjectInitializer& ObjectInitializer);
};
