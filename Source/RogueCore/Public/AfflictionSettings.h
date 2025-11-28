#pragma once
#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "ScaledMeshAfflictionTypeItem.h"
#include "AfflictionSettings.generated.h"

class UNiagaraSystem;
class UPawnAffliction;
class USoundCue;
UCLASS(Blueprintable)
class UAfflictionSettings : public UDataAsset {
    GENERATED_BODY()
    
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FScaledMeshAfflictionTypeItem FrozenScaledMeshAffliction;
    
    FScaledMeshAfflictionTypeItem InfectedScaledMeshAffliction;
    TSoftObjectPtr<USoundCue> BurningSound;
    float HeavyStaggerMinTime;
    float MediumStaggerMinTime;
    UPawnAffliction* HeavyStaggerAffliction;
    UPawnAffliction* MediumStaggerAffliction;
    UPawnAffliction* ShortStaggerAffliction;
 
    UPROPERTY(BlueprintReadWrite, EditAnywhere, EditFixedSize, meta=(AllowPrivateAccess=true))
    TArray<TSoftObjectPtr<UNiagaraSystem>> BurningParticles;
    TArray<TSoftObjectPtr<UNiagaraSystem>> EletrocutedParticles;
    TArray<TSoftObjectPtr<UNiagaraSystem>> ExplodingParticles;
    TArray<TSoftObjectPtr<USoundCue>> ExplodingSounds;
    UAfflictionSettings();
};
