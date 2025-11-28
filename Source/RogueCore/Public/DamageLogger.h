#pragma once
#include "CoreMinimal.h"
#include "DamageLogger.generated.h"

USTRUCT(BlueprintType)
struct FDamageLogger {
    GENERATED_BODY()
    
public:

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool LoggerEnabled;
    
    ROGUECORE_API FDamageLogger();
};
