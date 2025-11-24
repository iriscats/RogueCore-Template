#pragma once
#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "ButtonHoldSettings.h"
#include "BasicButtonHoldIndicatorAsset.generated.h"

UCLASS(Blueprintable)
class UBasicButtonHoldIndicatorAsset : public UDataAsset {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FButtonHoldSettings Settings;
    
    UBasicButtonHoldIndicatorAsset();
};
