#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "DynamicReverbComponent.generated.h"

class UAudioComponent;
UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class UDynamicReverbComponent : public UActorComponent {
    GENERATED_BODY()
    // UPROPERTY fields moved from protected section
public:

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float LargeCaveValue;
    
    float MediumCaveValue;
    float SmallCaveValue;
    float FadeTime;
    float Priority;
    float TunnelAmbienceFadeIn;
    float TunnelAmbienceFadeOut;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, Transient, meta=(AllowPrivateAccess=true))
    UAudioComponent* TunnelSoundInstance;
    UDynamicReverbComponent(const FObjectInitializer& ObjectInitializer);
    UFUNCTION(BlueprintCallable)
    void TunnelTimerTriggered();
    void TimerTriggered();
};
