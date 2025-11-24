#pragma once
#include "CoreMinimal.h"
#include "TXHandShake.generated.h"

USTRUCT(BlueprintType)
struct FTXHandShake {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FString gid;
    
    FString bid;
    FString pid;
    FString uid;
    ROGUECORE_API FTXHandShake();
};
