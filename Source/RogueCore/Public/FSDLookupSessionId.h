#pragma once
#include "CoreMinimal.h"
#include "FSDOnlineDelegates.h"
#include "Net/OnlineBlueprintCallProxyBase.h"
#include "FoundSessionResultDelegate.h"
#include "FSDLookupSessionId.generated.h"

class UFSDLookupSessionId;
class UObject;
UCLASS(Blueprintable, MinimalAPI)
class UFSDLookupSessionId : public UOnlineBlueprintCallProxyBase {
    GENERATED_BODY()
    // UPROPERTY fields moved from private section

public:
 
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FFoundSessionResult OnSuccess;
    
    FEmptyOnlineDelegate OnFailure;
    UFSDLookupSessionId();
    UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContextObject"))
    static UFSDLookupSessionId* FSDLookupSessionId(UObject* WorldContextObject, const FString& SessionKey);
};
