#pragma once
#include "CoreMinimal.h"
#include "FSDOnlineDelegates.h"
#include "Net/OnlineBlueprintCallProxyBase.h"
#include "OnlineSubsystemTypes.h"
#include "OnlineSessionInterface.h"
#include "Online/OnlineSessionSettings.h"
#include "FSDJoinSessionCallbackProxy.generated.h"

class APlayerController;
class UFSDJoinSessionCallbackProxy;
class UObject;
UCLASS(Blueprintable, MinimalAPI)
class UFSDJoinSessionCallbackProxy : public UOnlineBlueprintCallProxyBase {
    GENERATED_BODY()
    // UPROPERTY fields moved from private section
public:
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FEmptyOnlineDelegate OnSuccess;
    
    FEmptyOnlineDelegate OnFailure;
 
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    UObject* WorldContextObject;
    UFSDJoinSessionCallbackProxy();
    UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContextObject"))
    static UFSDJoinSessionCallbackProxy* FSDJoinSession(UObject* NewWorldContextObject, APlayerController* PlayerController, const FOnlineSessionSearchResult& SearchResult, const FString& fsdpassword, bool fromInvite);
};
