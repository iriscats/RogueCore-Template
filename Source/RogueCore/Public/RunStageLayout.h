#pragma once
#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "RunTemplateStage.h"
#include "RunStageLayout.generated.h"

UCLASS(Blueprintable)
class URunStageLayout : public UDataAsset {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FRunTemplateStage> Stages;
    
    URunStageLayout();
};
