#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "GameFramework/OnlineSession.h"
#include "FSDOnlineSessionClient.generated.h"

UCLASS(Blueprintable)
class UFSDOnlineSessionClient : public UOnlineSession {
    GENERATED_BODY()
public:
    UFSDOnlineSessionClient();
};
