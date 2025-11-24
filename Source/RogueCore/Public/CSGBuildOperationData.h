#pragma once
#include "CoreMinimal.h"
#include "CSGOptions.h"
#include "MatrixWithExactSync.h"
#include "Templates/SubclassOf.h"
#include "CSGBuildOperationData.generated.h"

class ACSGBuilder;
USTRUCT(BlueprintType)
struct FCSGBuildOperationData {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 OperationNumber;
    
    TSubclassOf<ACSGBuilder> CSGModel;
    FCSGOptions CarverSettings;
    FMatrixWithExactSync Transform;
    ROGUECORE_API FCSGBuildOperationData();
};
