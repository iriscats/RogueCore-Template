#pragma once
#include "CoreMinimal.h"
#include "TXLevelDecorationEvent.generated.h"

USTRUCT(BlueprintType)
struct FTXLevelDecorationEvent {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 amount_spawned_success;
    
    int32 amount_spawned_failures;
    TArray<FString> failures;
    int32 stage_index;
    ROGUECORE_API FTXLevelDecorationEvent();
};
