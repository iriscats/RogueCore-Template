#pragma once
#include "CoreMinimal.h"
#include "UObject/Interface.h"

#include "WeaponFireOwner.generated.h"

class APlayerCharacter;
UINTERFACE(BlueprintType, meta=(CannotImplementInterfaceInBlueprint))
class ROGUECORE_API UWeaponFireOwner : public UInterface {
	GENERATED_BODY()
};
class ROGUECORE_API IWeaponFireOwner : public IInterface {
	GENERATED_BODY()
public:
    UFUNCTION(BlueprintCallable)
    virtual APlayerCharacter* GetPlayerCharacter() const PURE_VIRTUAL(GetPlayerCharacter, return NULL;);
    
    virtual FQuat GetMuzzleQuat() const PURE_VIRTUAL(GetMuzzleQuat, return FQuat{};);
    virtual FVector GetMuzzleLocation() const PURE_VIRTUAL(GetMuzzleLocation, return FVector{};);
    virtual bool GetIsLocallyControlled() const PURE_VIRTUAL(GetIsLocallyControlled, return false;);
    virtual bool GetIsFirstPerson() const PURE_VIRTUAL(GetIsFirstPerson, return false;);
};