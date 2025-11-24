#pragma once
#include "CoreMinimal.h"
#include "PerkEffectComponent.h"
#include "Templates/SubclassOf.h"
#include "PerkEffectComponentShieldLink.generated.h"

class APlayerCharacter;
class UStatusEffect;
UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class UPerkEffectComponentShieldLink : public UPerkEffectComponent {
    GENERATED_BODY()
    // UPROPERTY fields moved from protected section

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))

    UStatusEffect* BoostedStatusEffectInstance;

    float LinkDistance;

    TSet<APlayerCharacter*> LinkedCharacters;

    TSubclassOf<UStatusEffect> LinkStatusEffect;

    UPerkEffectComponentShieldLink(const FObjectInitializer& ObjectInitializer);

    UFUNCTION(BlueprintCallable)

    void TimerFunction();



public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<UStatusEffect> BoostedStatusEffect;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    UStatusEffect* BoostedStatusEffectInstance;
    float LinkDistance;
    TSet<APlayerCharacter*> LinkedCharacters;
    TSubclassOf<UStatusEffect> LinkStatusEffect;
    UPerkEffectComponentShieldLink(const FObjectInitializer& ObjectInitializer);
    UFUNCTION(BlueprintCallable)
    void TimerFunction();
};
