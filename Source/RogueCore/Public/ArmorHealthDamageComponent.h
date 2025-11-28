#pragma once
#include "CoreMinimal.h"
#include "AmorPartDestroyedDelegateDelegate.h"
#include "ArmorDamageInfo.h"
#include "ArmorHealthItem.h"
#include "ArmorPartDamagedDelegateDelegate.h"
#include "BaseArmorDamageComponent.h"
#include "EArmorDamageType.h"
#include "ArmorHealthDamageComponent.generated.h"

class UPrimitiveComponent;
UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class UArmorHealthDamageComponent : public UBaseArmorDamageComponent {
    GENERATED_BODY()
    
public:
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FAmorPartDestroyedDelegate OnArmorPartDestroyedEvent;
    
    FArmorPartDamagedDelegate OnArmorPartDamagedEvent;
    FAmorPartDestroyedDelegate OnSocketPartDestroyedEvent;
    FArmorPartDamagedDelegate OnSocketPartDamagedEvent;
 
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<FName, FArmorHealthItem> PhysBoneToArmor;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, ReplicatedUsing=OnRep_ArmorDamageInfo, meta=(AllowPrivateAccess=true))
    FArmorDamageInfo ArmorDamageInfo;
    float RadialSocketDamageMultiplier;
    bool AffectedByAmorBreak;
    UArmorHealthDamageComponent(const FObjectInitializer& ObjectInitializer);
    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
    UFUNCTION(BlueprintCallable)
    bool SetHealthOnBodypartItem(FName BoneName, float newHealth);
    void SetHealthOnAllItems(float newHealth);
    bool SetArmorDamageEnabledOnItem(FName BoneName, bool Enabled);
    UFUNCTION(BlueprintAuthorityOnly, BlueprintCallable)
    void RegrowAllArmor(float BaseHealth);
    void PopAllWeakPoints();
    UFUNCTION()
    void OnRep_ArmorDamageInfo(FArmorDamageInfo OldValue);
    void DealSocketArmorDamage(float Damage, float armorDamageMultiplier, UPrimitiveComponent* collider, bool shatter, EArmorDamageType DamageType);
};
