#pragma once
#include "CoreMinimal.h"
#include "ECarveFilterType.h"
#include "EPreciousMaterialOptions.h"
#include "MatrixWithExactSync.h"
#include "CarveWithSTLMeshOperationData.generated.h"

class USTLMeshCarver;
class UStaticMeshCarver;
class UTerrainMaterial;
USTRUCT(BlueprintType)
struct FCarveWithSTLMeshOperationData {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 OperationNumber;
    
    USTLMeshCarver* STLMeshCarver;
    UStaticMeshCarver* StaticMeshCarver;
    UTerrainMaterial* Material;
    ECarveFilterType CarveFilter;
    EPreciousMaterialOptions Precious;
    FMatrixWithExactSync Transform;
    ROGUECORE_API FCarveWithSTLMeshOperationData();
};
