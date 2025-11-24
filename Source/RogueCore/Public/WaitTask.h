#pragma once
#include "CoreMinimal.h"
#include "LineSpikeTaskBase.h"
#include "WaitTask.generated.h"

UCLASS(Blueprintable, DefaultToInstanced, EditInlineNew)
class UWaitTask : public ULineSpikeTaskBase {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float WaitTime;
    
    bool SkipIfLast;
    bool OnlyOnce;
    UWaitTask();
};
