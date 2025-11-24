#pragma once
#include "CoreMinimal.h"
#include "EStageType.h"
#include "RunBranchStage.generated.h"

class UBiome;
USTRUCT(BlueprintType)
struct FRunBranchStage {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EStageType Type;
    
    UBiome* Biome;
    TArray<int32> BranchConnections;
    int32 StageBranchLevel;
    int32 StageIndex;
    bool IsDiscovered;
    ROGUECORE_API FRunBranchStage();
};
