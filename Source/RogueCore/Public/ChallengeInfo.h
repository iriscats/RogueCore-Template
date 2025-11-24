#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "ChallengeInfo.generated.h"

class UTexture2D;
USTRUCT(BlueprintType)
struct FChallengeInfo {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FText Text;
    
    UTexture2D* Icon;
    UTexture2D* IconOutlined;
    FLinearColor Color;
    int32 CurrentWins;
    int32 NumberOfWins;
    int32 XPCompleteGain;
    int32 TokenGain;
    TSoftObjectPtr<UTexture2D> Stat1Image;
    TSoftObjectPtr<UTexture2D> Stat2Image;
    bool bIsSpecial;
    ROGUECORE_API FChallengeInfo();
};
