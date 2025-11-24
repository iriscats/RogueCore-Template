#pragma once
#include "CoreMinimal.h"
#include "TXNetworkFailureEvent.generated.h"

USTRUCT(BlueprintType)
struct FTXNetworkFailureEvent {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FString error_type;
    
    FString error_message;
    bool is_host;
    float connection_duration;
    ROGUECORE_API FTXNetworkFailureEvent();
};
