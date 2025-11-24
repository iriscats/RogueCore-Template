#pragma once
#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "Templates/SubclassOf.h"
#include "DamageParamBonus.generated.h"

class UDamageParamBonus;
class UObject;
UCLASS(Abstract, Blueprintable, EditInlineNew)
class UDamageParamBonus : public UDataAsset {
    GENERATED_BODY()
public:
    UDamageParamBonus();
    UFUNCTION(BlueprintCallable)
    static UDamageParamBonus* CreateDamageParamBonus(TSubclassOf<UDamageParamBonus> SubClass, UObject* Owner);
    
};
