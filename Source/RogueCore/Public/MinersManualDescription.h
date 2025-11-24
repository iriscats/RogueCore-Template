#pragma once
#include "CoreMinimal.h"
#include "MinersManualDescription.generated.h"

class UTexture2D;
USTRUCT(BlueprintType)
struct FMinersManualDescription {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FText Headline;
    
    FText RichDescription;
    UTexture2D* ImageFront;
    UTexture2D* ImageBackground;
    ROGUECORE_API FMinersManualDescription();
};
