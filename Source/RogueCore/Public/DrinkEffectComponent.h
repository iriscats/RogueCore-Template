#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "DrinkEffectComponent.generated.h"

class APlayerCharacter;
UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class UDrinkEffectComponent : public UActorComponent {
    GENERATED_BODY()
    // UPROPERTY fields moved from protected section
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float BeerEffectDurationSeconds;
    
    bool AutoDestroy;
    bool EffectIsActive;
    bool ActivatesOnlyOnceWhenDrinking;
    UDrinkEffectComponent(const FObjectInitializer& ObjectInitializer);
    UFUNCTION(BlueprintCallable)
    void StopEffect();
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnStopEffect();
    void OnStartEffect(APlayerCharacter* Character);
    static void OnChangedCharacter(APlayerCharacter* changedToCharacter, UClass* DrinkEffectClass);
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool GetActivateOnlyWhenDrinking() const;
};
