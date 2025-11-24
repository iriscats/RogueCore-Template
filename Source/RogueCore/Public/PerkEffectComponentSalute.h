#pragma once
#include "CoreMinimal.h"
#include "PerkEffectComponent.h"
#include "PerkEffectComponentSalute.generated.h"

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class UPerkEffectComponentSalute : public UPerkEffectComponent {
    GENERATED_BODY()
    // UPROPERTY fields moved from protected section

public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float CoolDown;
    
    float FleeRadius;
    UPerkEffectComponentSalute(const FObjectInitializer& ObjectInitializer);
    UFUNCTION(BlueprintCallable)
    void OnSalute();
};
