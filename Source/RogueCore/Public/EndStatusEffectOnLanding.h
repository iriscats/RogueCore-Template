#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "ECharacterState.h"
#include "StatusAddedComponent.h"
#include "EndStatusEffectOnLanding.generated.h"

class UStatusEffect;
UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class UEndStatusEffectOnLanding : public UActorComponent, public IStatusAddedComponent {
    GENERATED_BODY()
    // UPROPERTY fields moved from protected section

public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TWeakObjectPtr<UStatusEffect> EffectToCancel;
    
    UEndStatusEffectOnLanding(const FObjectInitializer& ObjectInitializer);
    UFUNCTION(BlueprintCallable)
    void OnOwnerStateChanged(ECharacterState State);
    // Fix for true pure virtual functions not being implemented
};
