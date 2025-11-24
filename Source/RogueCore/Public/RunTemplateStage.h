#pragma once
#include "CoreMinimal.h"
#include "EStageType.h"
#include "RunMutatorOverrides.h"
#include "RunObjectiveOverrides.h"
#include "RunTemplateObjectiveSettings.h"
#include "RunTemplateStageSettings.h"
#include "RunTemplateStage.generated.h"

class UStageTemplateDifficulty;
class UWorld;
USTRUCT(BlueprintType)
struct FRunTemplateStage {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<int32> NextBranchOptions;
    
    EStageType Type;
    UStageTemplateDifficulty* StageDifficulty;
    FRunTemplateObjectiveSettings ObjectiveSettings;
    FRunObjectiveOverrides ObjectiveOverrides;
    FRunMutatorOverrides MutatorOverrides;
    FRunTemplateStageSettings StageSettings;
    TSoftObjectPtr<UWorld> SafeRoomLevel;
    ROGUECORE_API FRunTemplateStage();
};
