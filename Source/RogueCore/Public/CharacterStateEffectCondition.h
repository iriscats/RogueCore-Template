#pragma once
#include "CoreMinimal.h"
#include "ECharacterState.h"
#include "EffectTriggerCondition.h"
#include "CharacterStateEffectCondition.generated.h"

UCLASS(Blueprintable, EditInlineNew)
class UCharacterStateEffectCondition : public UEffectTriggerCondition {
    GENERATED_BODY()
    

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    ECharacterState TargetState;

    UCharacterStateEffectCondition();

};
