#pragma once
#include "CoreMinimal.h"

#include "HitscanWeapon.h"
#include "BasicPistol.generated.h"

class UFSDPhysicalMaterial;
class UHealthComponentBase;
class UPrimitiveComponent;
UCLASS(Blueprintable)
class ABasicPistol : public AHitscanWeapon {
    GENERATED_BODY()
    


public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float BurstArmorDamageMultiplier;
    
    float ConsecutiveHitsDamageBonus;
    float ConsecutiveHitsMaxBonus;
    ABasicPistol(const FObjectInitializer& ObjectInitializer);
    UFUNCTION(BlueprintCallable)
    void OnTargetDamaged(UHealthComponentBase* Health, float amount, UPrimitiveComponent* HitComponent, UFSDPhysicalMaterial* PhysicalMaterial);
    void OnHit(const FHitResult& HitResult, bool isAlwaysPenetrated);
};
