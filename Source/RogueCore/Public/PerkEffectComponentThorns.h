#pragma once
#include "CoreMinimal.h"
#include "DamageData.h"
#include "PerkEffectComponent.h"
#include "Templates/SubclassOf.h"
#include "PerkEffectComponentThorns.generated.h"

class UDamageClass;
class UHealthComponentBase;
class UStatusEffect;
UCLASS(Abstract, Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class UPerkEffectComponentThorns : public UPerkEffectComponent {
    GENERATED_BODY()
    // UPROPERTY fields moved from protected section


public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UDamageClass* DamageClass;
    
    UDamageClass* PhysicalDamageClass;
    float CoolDown;
    TSubclassOf<UStatusEffect> ThornsSTE;
    UPerkEffectComponentThorns(const FObjectInitializer& ObjectInitializer);
    UFUNCTION(BlueprintCallable)
    void OnHit(float Damage, const FDamageData& DamageData, bool anyHealthLost, UHealthComponentBase* HealthComponent);
};
