#pragma once
#include "CoreMinimal.h"
#include "TXPlayerStat.generated.h"

USTRUCT(BlueprintType)
struct FTXPlayerStat {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FString Name;
    
    int32 amount;
    ROGUECORE_API FTXPlayerStat();
};
