#pragma once
#include "CoreMinimal.h"
#include "CustomCounterDelegateDelegate.h"
#include "CustomCounter.generated.h"

class UObject;
USTRUCT(BlueprintType)
struct FCustomCounter {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FCustomCounterDelegate OnCount;
    
    TWeakObjectPtr<UObject> Owner;
    ROGUECORE_API FCustomCounter();
};
