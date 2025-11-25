#pragma once
#include "CoreMinimal.h"
#include "EmitterConnection.generated.h"

USTRUCT(BlueprintType)
struct ROGUECORE_API FEmitterConnection {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName VariableName;

    FEmitterConnection();
};
