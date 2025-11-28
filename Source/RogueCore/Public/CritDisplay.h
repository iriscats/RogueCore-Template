#pragma once
#include "CoreMinimal.h"

#include "Runtime/SlateCore/Public/Fonts/SlateFontInfo.h"
#include "CritDisplay.generated.h"

class USoundBase;
USTRUCT(BlueprintType)
struct FCritDisplay {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FLinearColor DisplayColor = FLinearColor::White;
    
    FSlateFontInfo DisplayFont;
    FString Suffix;
    USoundBase* SoundEffect;

};
