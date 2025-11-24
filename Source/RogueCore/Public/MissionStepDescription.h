#pragma once
#include "CoreMinimal.h"
#include "MissionStepDescription.generated.h"

class UTexture2D;
USTRUCT(BlueprintType)
struct FMissionStepDescription {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FText Headline;
    
    FText RichDescription;
    UTexture2D* Image;
    ROGUECORE_API FMissionStepDescription();
};
