#pragma once
#include "CoreMinimal.h"
#include "Mutator.h"
#include "InfestedEnemiesMutator.generated.h"

class AFSDPawn;
class UFXSystemAsset;
UCLASS(Blueprintable, EditInlineNew)
class UInfestedEnemiesMutator : public UMutator {
    GENERATED_BODY()
    // UPROPERTY fields moved from protected section

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<UFXSystemAsset*> SpawnEffects;

    UInfestedEnemiesMutator();

    UFUNCTION(BlueprintCallable, BlueprintPure, meta=(AllowPrivateAccess=true))
    UFXSystemAsset* GetParticleSystem(AFSDPawn* Enemy) const;

};
