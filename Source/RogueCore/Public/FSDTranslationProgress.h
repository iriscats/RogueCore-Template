#pragma once
#include "CoreMinimal.h"
#include "FSDTranslationProgress.generated.h"

USTRUCT(BlueprintType)
struct FFSDTranslationProgress {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FString CodeName;
    
    int32 TranslatedPercent;
    ROGUECORE_API FFSDTranslationProgress();
};
