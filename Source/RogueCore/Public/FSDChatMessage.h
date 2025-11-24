#pragma once
#include "CoreMinimal.h"
#include "Engine/NetSerialization.h"
#include "EChatMessageType.h"
#include "EChatSenderType.h"
#include "FSDChatMessage.generated.h"

USTRUCT(BlueprintType)
struct FFSDChatMessage {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EChatMessageType MsgType;
    
    FString Sender;
    EChatSenderType SenderType;
    FString Msg;
    FUniqueNetIdRepl SenderNetID;
    ROGUECORE_API FFSDChatMessage();
};
