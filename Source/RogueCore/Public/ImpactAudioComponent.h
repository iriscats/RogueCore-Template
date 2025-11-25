#pragma once
#include "CoreMinimal.h"
#include "Components/AudioComponent.h"
#include "Templates/SubclassOf.h"
#include "ImpactAudioComponent.generated.h"

class AActor;
class UHealthComponentBase;
class UImpactAudioComponent;
class USceneComponent;
UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class UImpactAudioComponent : public UAudioComponent {
    GENERATED_BODY()

public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName AudioParameterSpeed;
    
    float DecelerationThreshold;
    bool ListenForDeath;
    UImpactAudioComponent(const FObjectInitializer& ObjectInitializer);
    UFUNCTION(BlueprintCallable)
    void OnOwnerDeath(UHealthComponentBase* HealthComponent);
    static UImpactAudioComponent* AddImpactAudioToActor(AActor* Actor, USceneComponent* AttachToComponent, TSubclassOf<UImpactAudioComponent> ComponentClass);
};
