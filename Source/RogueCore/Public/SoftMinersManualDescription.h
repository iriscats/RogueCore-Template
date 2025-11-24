#pragma once
#include "CoreMinimal.h"
#include "SoftMinersManualDescription.generated.h"

class UTexture2D;
USTRUCT(BlueprintType)
struct FSoftMinersManualDescription {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FText Headline;
    
    FText RichDescription;
    TSoftObjectPtr<UTexture2D> ImageFront;
    TSoftObjectPtr<UTexture2D> ImageBackground;
    ROGUECORE_API FSoftMinersManualDescription();
};
