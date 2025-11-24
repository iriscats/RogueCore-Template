#pragma once
#include "CoreMinimal.h"
#include "PerkEffectComponent.h"
#include "PerkEffectComponentBerserk.generated.h"

class UPawnStat;
UCLASS(Abstract, Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class UPerkEffectComponentBerserk : public UPerkEffectComponent {
    GENERATED_BODY()
    // UPROPERTY fields moved from protected section

public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UPawnStat* BoostedStat;
    
    float AmountPerValue;
    UPerkEffectComponentBerserk(const FObjectInitializer& ObjectInitializer);
    UFUNCTION(BlueprintCallable)
    void OnHealthChanged(float Health);
};
