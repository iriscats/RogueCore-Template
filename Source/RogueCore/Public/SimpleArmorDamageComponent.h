#pragma once
#include "CoreMinimal.h"
#include "ArmorDamageInfo.h"
#include "BaseArmorDamageComponent.h"
#include "DestructableBodypartItem.h"
#include "SimpleArmorRadialDamagedDelegateDelegate.h"
#include "SimpleArmorDamageComponent.generated.h"

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class USimpleArmorDamageComponent : public UBaseArmorDamageComponent {
    GENERATED_BODY()
    // UPROPERTY fields moved from protected section

public:
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSimpleArmorRadialDamagedDelegate OnRadialArmorPartsDestroyedEvent;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float ArmorStrength;
    TMap<FName, FDestructableBodypartItem> PhysBoneToArmor;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, ReplicatedUsing=OnRep_ArmorDamageInfo, meta=(AllowPrivateAccess=true))
    FArmorDamageInfo ArmorDamageInfo;
    USimpleArmorDamageComponent(const FObjectInitializer& ObjectInitializer);
    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
    UFUNCTION(BlueprintCallable)
    void OnRep_ArmorDamageInfo(FArmorDamageInfo OldArmorDamageInfo);
};
