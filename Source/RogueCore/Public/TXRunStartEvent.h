#pragma once
#include "CoreMinimal.h"
#include "TXRunStartEvent.generated.h"

USTRUCT(BlueprintType)
struct FTXRunStartEvent {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 player_count;
    
    TArray<FString> runs_unlocked;
    TArray<FString> equipped_decks;
    int32 enhancement_xp;
    TArray<FString> equipped_enhancements;
    ROGUECORE_API FTXRunStartEvent();
};
