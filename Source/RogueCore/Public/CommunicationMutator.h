#pragma once
#include "CoreMinimal.h"
#include "Mutator.h"
#include "CommunicationMutator.generated.h"

UCLASS(Blueprintable, EditInlineNew)
class UCommunicationMutator : public UMutator {
    GENERATED_BODY()
    // UPROPERTY fields moved from protected section

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float PitchMultiplier;

    UCommunicationMutator();

};
