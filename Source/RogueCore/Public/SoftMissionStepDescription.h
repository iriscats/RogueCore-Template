#pragma once
#include "CoreMinimal.h"
#include "SoftMissionStepDescription.generated.h"

class UTexture2D;
USTRUCT(BlueprintType)
struct FSoftMissionStepDescription {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FText Headline;
    
    FText RichDescription;
    TSoftObjectPtr<UTexture2D> Image;
    ROGUECORE_API FSoftMissionStepDescription();
};
