#pragma once
#include "CoreMinimal.h"
#include "Online/CoreOnline.h"
#include "SessionSearchResultTypes.h"
#include "FSDOnlineDelegates.h"
#include "Net/OnlineBlueprintCallProxyBase.h"
#include "FSDJoinSessionCallbackProxy.generated.h"

class APlayerController;
class UFSDJoinSessionCallbackProxy;
class UObject;
UCLASS(Blueprintable, MinimalAPI)
class UFSDJoinSessionCallbackProxy : public UOnlineBlueprintCallProxyBase {
    GENERATED_BODY()
    
public:
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FEmptyOnlineDelegate OnSuccess;
    
    FEmptyOnlineDelegate OnFailure;
 
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    UObject* WorldContextObject;
    UFSDJoinSessionCallbackProxy();
    UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContextObject"))
    static UFSDJoinSessionCallbackProxy* FSDJoinSession(UObject* NewWorldContextObject, APlayerController* PlayerController, const FSessionSearchResultWrapper& SearchResultWrapper, const FString& fsdpassword, bool fromInvite);
};
