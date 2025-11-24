#pragma once
#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "EHealthbarType.h"
#include "Health.generated.h"

class AActor;
UINTERFACE(BlueprintType, meta=(CannotImplementInterfaceInBlueprint))
class ROGUECORE_API UHealth : public UInterface {
	GENERATED_BODY()
};
class ROGUECORE_API IHealth : public IInterface {
	GENERATED_BODY()
public:
    UFUNCTION(BlueprintCallable)
    virtual bool IsDead() const PURE_VIRTUAL(IsDead, return false;);
    
    virtual bool IsAlive() const PURE_VIRTUAL(IsAlive, return false;);
    virtual AActor* GetOwner() const PURE_VIRTUAL(GetOwner, return NULL;);
    virtual float GetMaxHealth() const PURE_VIRTUAL(GetMaxHealth, return 0.0f;);
    virtual EHealthbarType GetHealthbarType() const PURE_VIRTUAL(GetHealthbarType, return EHealthbarType::None;);
    virtual float GetHealth() const PURE_VIRTUAL(GetHealth, return 0.0f;);
};
