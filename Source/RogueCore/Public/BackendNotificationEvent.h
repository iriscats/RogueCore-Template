#pragma once
#include "CoreMinimal.h"
#include "BackendNotificationEvent.generated.h"

USTRUCT(BlueprintType)
struct FBackendNotificationEvent {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FString MessageType;
    
    FString Header;
    FString Message;
    FString Link;
    ROGUECORE_API FBackendNotificationEvent();
};
