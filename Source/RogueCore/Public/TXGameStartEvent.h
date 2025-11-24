#pragma once
#include "CoreMinimal.h"
#include "TXGameStartEvent.generated.h"

USTRUCT(BlueprintType)
struct FTXGameStartEvent {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FString CPU;
    
    FString GPU;
    FString game_language;
    bool mods_enabled;
    FString os_language;
    FString screen_res;
    ROGUECORE_API FTXGameStartEvent();
};
