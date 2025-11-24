#pragma once
#include "CoreMinimal.h"
#include "ElementEventState.generated.h"

class AActor;
class UElementEventType;
class UElementType;
USTRUCT(BlueprintType)
struct FElementEventState {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UElementEventType* EventType;
    
    UElementType* TriggeredByElementType;
    AActor* Source;
    float StartTime;
    float LockDuration;
    ROGUECORE_API FElementEventState();
};
