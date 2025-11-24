#pragma once
#include "CoreMinimal.h"
#include "HealthComponent.h"
#include "FriendlyHealthComponent.generated.h"

class UFXSystemAsset;
UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class UFriendlyHealthComponent : public UHealthComponent {
    GENERATED_BODY()
    // UPROPERTY fields moved from protected section
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float MaxHealth;
    
    float FriendlyFireModifier;
    float NeutralDamageModifier;
    float BigHitDamageModifier;
    float BigHitDamageReductionThreshold;
    UFXSystemAsset* GenericImpactParticles;
    UFriendlyHealthComponent(const FObjectInitializer& ObjectInitializer);
    virtual float GetMaxHealth() const override;
};
