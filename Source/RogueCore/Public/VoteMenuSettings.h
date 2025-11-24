#pragma once
#include "CoreMinimal.h"
#include "VoteMenuSettings.generated.h"

class UVoteWidget;
USTRUCT(BlueprintType)
struct FVoteMenuSettings {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSoftClassPtr<UVoteWidget> VoteWidget;
    
    int32 Z_Order;
    int32 Countdown;
    ROGUECORE_API FVoteMenuSettings();
};
