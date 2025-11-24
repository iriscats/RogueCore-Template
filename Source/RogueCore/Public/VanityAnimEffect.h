#pragma once
#include "CoreMinimal.h"
#include "VanityAnimEffect.generated.h"

class UNiagaraSystem;
USTRUCT(BlueprintType)
struct FVanityAnimEffect {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UNiagaraSystem* Effect;
    
    FName AttachSocket;
    float StartDelay;
    ROGUECORE_API FVanityAnimEffect();
};
