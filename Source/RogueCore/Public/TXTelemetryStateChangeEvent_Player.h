#pragma once
#include "CoreMinimal.h"
#include "TXTelemetryStateChangeEvent_Player.generated.h"

USTRUCT(BlueprintType)
struct FTXTelemetryStateChangeEvent_Player {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 player_rank;
    
    FString played_class;
    int32 class_level;
    bool is_host;
    TArray<FString> equipped_perks;
    ROGUECORE_API FTXTelemetryStateChangeEvent_Player();
};
