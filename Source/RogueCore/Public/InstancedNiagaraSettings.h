#pragma once
#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "SystemSettings.h"
#include "InstancedNiagaraSettings.generated.h"

class UNiagaraSystem;
UCLASS(Blueprintable)
class UInstancedNiagaraSettings : public UDataAsset {
    GENERATED_BODY()
    // UPROPERTY fields moved from protected section

public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<UNiagaraSystem*, FSystemSettings> SystemSettings;
    
    UInstancedNiagaraSettings();
};
