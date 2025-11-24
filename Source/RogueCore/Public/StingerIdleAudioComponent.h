#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "StingerIdleAudioComponent.generated.h"

class UAudioComponent;
class UHealthComponentBase;
UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class ROGUECORE_API UStingerIdleAudioComponent : public UActorComponent {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Export, Transient, meta=(AllowPrivateAccess=true))
    TWeakObjectPtr<UAudioComponent> AudioComponent;
    
    TWeakObjectPtr<UHealthComponentBase> HealthComponent;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float FadeInTime;
    float FadeOutTime;
    UStingerIdleAudioComponent(const FObjectInitializer& ObjectInitializer);
};
