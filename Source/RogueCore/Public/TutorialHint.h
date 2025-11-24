#pragma once
#include "CoreMinimal.h"
#include "TutorialHint.generated.h"

class UTexture2D;
USTRUCT(BlueprintType)
struct FTutorialHint {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FText Text;
    
    FText TaskText;
    FText Title;
    TSoftObjectPtr<UTexture2D> Image;
    ROGUECORE_API FTutorialHint();
};
