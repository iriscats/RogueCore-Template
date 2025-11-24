#pragma once
#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "StageSettings.generated.h"

class UStageNameBank;
UCLASS(Blueprintable)
class UStageSettings : public UDataAsset {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UStageNameBank* StageNames;
    
    UStageSettings();
};
