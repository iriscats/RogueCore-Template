#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "DiscordRewardNotification.generated.h"

class UTexture2D;
USTRUCT(BlueprintType)
struct FDiscordRewardNotification {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FText Text;
    
    UTexture2D* Icon;
    FLinearColor IconColor;
    FString ID;
    ROGUECORE_API FDiscordRewardNotification();
};
