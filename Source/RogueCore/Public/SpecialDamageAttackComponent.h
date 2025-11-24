#pragma once
#include "CoreMinimal.h"
#include "SpecialAttackComponent.h"
#include "SpecialDamageAttackComponent.generated.h"

class UDamageAsset;
class UDamageComponent;
UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class USpecialDamageAttackComponent : public USpecialAttackComponent {
    GENERATED_BODY()
    // UPROPERTY fields moved from protected section


public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UDamageAsset* AttackDamage;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UDamageComponent* Damage;
    USpecialDamageAttackComponent(const FObjectInitializer& ObjectInitializer);
};
