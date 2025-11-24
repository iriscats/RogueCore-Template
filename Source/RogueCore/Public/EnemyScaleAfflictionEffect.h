#pragma once
#include "CoreMinimal.h"
#include "AfflictionEffect.h"
#include "EnemyScaleAfflictionEffect.generated.h"

UCLASS(Abstract, Blueprintable)
class UEnemyScaleAfflictionEffect : public UAfflictionEffect {
    GENERATED_BODY()

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float Scale;

    bool RevertOnEndEffect;

public:
    UEnemyScaleAfflictionEffect();
};
