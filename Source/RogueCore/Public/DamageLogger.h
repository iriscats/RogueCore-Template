#pragma once
#include "CoreMinimal.h"
#include "DamageLogger.generated.h"

USTRUCT(BlueprintType)
struct FDamageLogger {
    GENERATED_BODY()
    // UPROPERTY fields moved from protected section
public:

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool LoggerEnabled;
    
    ROGUECORE_API FDamageLogger();
};
