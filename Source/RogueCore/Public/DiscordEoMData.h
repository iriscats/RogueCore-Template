#pragma once
#include "CoreMinimal.h"
#include "DiscordEoMData.generated.h"

USTRUCT(BlueprintType)
struct FDiscordEoMData {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FString nick;
    
    FString UserId;
    ROGUECORE_API FDiscordEoMData();
};
