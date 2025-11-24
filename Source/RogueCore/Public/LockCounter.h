#pragma once
#include "CoreMinimal.h"
#include "LockCounter.generated.h"

class AActor;
USTRUCT(BlueprintType)
struct FLockCounter {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    int32 LockCount;
    
    TWeakObjectPtr<AActor> LockedActor;
    ROGUECORE_API FLockCounter();
};
