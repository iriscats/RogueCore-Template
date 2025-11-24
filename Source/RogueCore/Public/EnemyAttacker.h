#pragma once
#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "EnemyAttacker.generated.h"

UINTERFACE(BlueprintType, meta=(CannotImplementInterfaceInBlueprint))
class ROGUECORE_API UEnemyAttacker : public UInterface {
	GENERATED_BODY()
};
class ROGUECORE_API IEnemyAttacker : public IInterface {
	GENERATED_BODY()
public:
    UFUNCTION(BlueprintCallable)
    virtual float GetAttackDamageModifier() const PURE_VIRTUAL(GetAttackDamageModifier, return 0.0f;);
};
    
