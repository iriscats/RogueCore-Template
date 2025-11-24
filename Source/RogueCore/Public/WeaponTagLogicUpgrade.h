#pragma once
#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "TagEffectDataBase.h"
#include "WeaponTagInitData.h"
#include "WeaponTagLogicUpgrade.generated.h"

UINTERFACE(Blueprintable)
class ROGUECORE_API UWeaponTagLogicUpgrade : public UInterface {
	GENERATED_BODY()
};
class ROGUECORE_API IWeaponTagLogicUpgrade : public IInterface {
	GENERATED_BODY()
public:
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void Recieve_Init(const FWeaponTagInitData& effectData);
    
    void Receive_OnUnEquipped(const FTagEffectDataBase& effectData);
    void Receive_OnStoppedReloading(const FTagEffectDataBase& effectData);
    void Receive_OnStartedReloading(const FTagEffectDataBase& effectData);
    void Receive_OnPowerAttack(const FTagEffectDataBase& effectData);
    void Receive_OnKill(const FTagEffectDataBase& effectData);
    void Receive_OnHit(const FTagEffectDataBase& effectData);
    void Receive_OnEquipped(const FTagEffectDataBase& effectData);
    void Receive_OnCrit(const FTagEffectDataBase& effectData);
    void Receive_OnAddedToInventory(const FTagEffectDataBase& effectData);
};
