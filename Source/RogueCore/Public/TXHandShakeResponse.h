#pragma once
#include "CoreMinimal.h"
#include "TXHandShakeResponse.generated.h"

USTRUCT(BlueprintType)
struct FTXHandShakeResponse {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FString sid;
    
    FString turi;
    FString topic;
    ROGUECORE_API FTXHandShakeResponse();
};
