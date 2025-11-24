#pragma once
#include "CoreMinimal.h"
#include "BackendNotification.generated.h"

USTRUCT(BlueprintType)
struct FBackendNotification {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FString Platform;
    
    FString Header;
    FString Message;
    FString MessageType;
    FString Link;
    ROGUECORE_API FBackendNotification();
};
