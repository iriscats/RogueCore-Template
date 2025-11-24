#pragma once
#include "CoreMinimal.h"
#include "FSDThreadStats.h"
#include "FSDThreadGroup.generated.h"

USTRUCT(BlueprintType)
struct ROGUECORE_API FFSDThreadGroup {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FString Name;
    
    TArray<FFSDThreadStats> Threads;
    FFSDThreadGroup();
};
