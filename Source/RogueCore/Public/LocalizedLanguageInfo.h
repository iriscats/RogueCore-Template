#pragma once
#include "CoreMinimal.h"
#include "LocalizedLanguageInfo.generated.h"

USTRUCT(BlueprintType)
struct FLocalizedLanguageInfo {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FString EnglishName;
    
    FString NativeName;
    FString CodeName;
    bool CommunityTranslated;
    int32 TranslatedPercent;
    ROGUECORE_API FLocalizedLanguageInfo();
};
