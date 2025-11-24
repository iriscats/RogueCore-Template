#pragma once
#include "CoreMinimal.h"
#include "EChatMessageType.h"
#include "FSDLocalizedChatMessage.generated.h"

USTRUCT(BlueprintType)
struct FFSDLocalizedChatMessage {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EChatMessageType MsgType;
    
    FString Sender;
    FText Msg;
    TArray<FText> Arguments;
    ROGUECORE_API FFSDLocalizedChatMessage();
};
