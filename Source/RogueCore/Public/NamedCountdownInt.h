#pragma once
#include "CoreMinimal.h"
#include "ENamedCountdownState.h"
#include "NamedCountdownInt.generated.h"

USTRUCT(BlueprintType)
struct FNamedCountdownInt {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName Name;
    
    ENamedCountdownState State;
    int32 SecondsRemaining;
    ROGUECORE_API FNamedCountdownInt();
};
