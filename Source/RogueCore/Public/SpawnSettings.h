#pragma once
#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "RandRange.h"
#include "SpawnSettings.generated.h"

class UNiagaraSystem;
class USoundCue;
UCLASS(Blueprintable)
class USpawnSettings : public UDataAsset {
    GENERATED_BODY()
    // UPROPERTY fields moved from protected section

public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, EditFixedSize, meta=(AllowPrivateAccess=true))
    TArray<UNiagaraSystem*> SpawnEffects;
    
    TArray<USoundCue*> SpawnSounds;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FRandRange SpawnDuration;
    USpawnSettings();
};
