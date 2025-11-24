#pragma once
#include "CoreMinimal.h"
#include "ENamedCountdownState.h"
#include "NamedCountdownFloat.generated.h"

USTRUCT(BlueprintType)
struct FNamedCountdownFloat {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName Name;
    
    ENamedCountdownState State;
    float SecondsRemaining;
    bool HaveQuickFinish;
    TArray<int32> StartedByPlayerIds;
    ROGUECORE_API FNamedCountdownFloat();
};
