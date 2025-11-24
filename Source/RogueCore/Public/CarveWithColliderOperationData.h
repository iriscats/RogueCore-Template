#pragma once
#include "CoreMinimal.h"
#include "CarveOptionsCellSize.h"
#include "ECarveFilterType.h"
#include "EPreciousMaterialOptions.h"
#include "MatrixWithExactSync.h"
#include "CarveWithColliderOperationData.generated.h"

class UStaticMesh;
class UTerrainMaterial;
USTRUCT(BlueprintType)
struct FCarveWithColliderOperationData {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 OperationNumber;
    
    UStaticMesh* StaticMesh;
    UTerrainMaterial* Material;
    ECarveFilterType CarveFilter;
    FMatrixWithExactSync Transform;
    float ExpensiveNoise;
    EPreciousMaterialOptions Precious;
    CarveOptionsCellSize CarveCellSize;
    bool AnchorCenterPoint;
    ROGUECORE_API FCarveWithColliderOperationData();
};
