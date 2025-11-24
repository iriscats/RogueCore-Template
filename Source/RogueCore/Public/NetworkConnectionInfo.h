#pragma once
#include "CoreMinimal.h"
#include "NetworkConnectionInfo.generated.h"

class AFSDPlayerController;
USTRUCT(BlueprintType)
struct FNetworkConnectionInfo {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    AFSDPlayerController* PlayerController;
    
    float PacketLossIn;
    float PacketLossOut;
    float Ping;
    float Jitter;
    bool IsValid;
    ROGUECORE_API FNetworkConnectionInfo();
};
