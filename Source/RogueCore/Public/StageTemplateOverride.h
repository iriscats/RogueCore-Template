#pragma once
#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "EStageType.h"
#include "RunMutatorOverrides.h"
#include "RunObjectiveOverrides.h"
#include "RunTemplateStageSettings.h"
#include "StageTemplateOverride.generated.h"

class UWorld;
UCLASS(Blueprintable)
class UStageTemplateOverride : public UDataAsset {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EStageType Type;
    
    FRunObjectiveOverrides Objectives;
    FRunMutatorOverrides Mutators;
    FRunTemplateStageSettings Settings;
    TSoftObjectPtr<UWorld> SafeRoomLevel;
    UStageTemplateOverride();
};
