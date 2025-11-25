#pragma once
#include "CoreMinimal.h"
#include "EmitterConnection.h"
#include "SystemSettings.generated.h"

USTRUCT(BlueprintType)
struct FRogueSystemSettings {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FEmitterConnection> EmitterParamConnections;

    FRogueSystemSettings() {
    }
};
