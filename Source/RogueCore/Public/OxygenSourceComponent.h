#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "OxygenActiveDelegateDelegate.h"
#include "OxygenSourceComponent.generated.h"

class UNoOxygenMutator;
UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class UOxygenSourceComponent : public UActorComponent {
    GENERATED_BODY()
    // UPROPERTY fields moved from protected section
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float SourceRadius;
    
    float CenterOffset;
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOxygenActiveDelegate OnOxygenActivationChanged;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    UNoOxygenMutator* Mutator;
    UOxygenSourceComponent(const FObjectInitializer& ObjectInitializer);
    UFUNCTION(BlueprintCallable)
    void OnTimerTick();
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnSourceActivated();
};
