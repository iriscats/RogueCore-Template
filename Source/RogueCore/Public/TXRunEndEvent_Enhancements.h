#pragma once
#include "CoreMinimal.h"
#include "TXRunEndEvent_Enhancements.generated.h"

USTRUCT(BlueprintType)
struct FTXRunEndEvent_Enhancements {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 shards_earned;
    
    int32 total_shards_earned;
    int32 shards_spent;
    TArray<FString> enhancements_unlocked;
    ROGUECORE_API FTXRunEndEvent_Enhancements();
};
