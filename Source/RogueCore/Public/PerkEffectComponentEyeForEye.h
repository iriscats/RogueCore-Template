#pragma once
#include "CoreMinimal.h"
#include "DamageData.h"
#include "PerkEffectComponent.h"
#include "Templates/SubclassOf.h"
#include "PerkEffectComponentEyeForEye.generated.h"

class UDamageClass;
class UHealthComponentBase;
class UStatusEffect;
UCLASS(Abstract, Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class UPerkEffectComponentEyeForEye : public UPerkEffectComponent {
    GENERATED_BODY()
    

public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float CoolDown;
    
    TSoftClassPtr<UStatusEffect> EyeForEyeSTE;
    UDamageClass* PhysicalDamageClass;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TSubclassOf<UStatusEffect> LoadedSTE;
    UPerkEffectComponentEyeForEye(const FObjectInitializer& ObjectInitializer);
    UFUNCTION(BlueprintCallable)
    void OnHit(float Damage, const FDamageData& DamageData, bool anyHealthLost, UHealthComponentBase* HealthComponent);
};
