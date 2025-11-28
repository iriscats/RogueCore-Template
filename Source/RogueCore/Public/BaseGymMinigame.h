#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "EGymGamemode.h"
#include "BaseGymMinigame.generated.h"

class UFitnessGymStateComponent;
class UGymActivityProperties;
class UGymMinigameBaseWidget;
UCLASS(Abstract, Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class UBaseGymMinigame : public UActorComponent {
    GENERATED_BODY()
    

public:

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UGymActivityProperties* Properties;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, Transient, meta=(AllowPrivateAccess=true))
    UFitnessGymStateComponent* GymComponent;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGymMinigameBaseWidget* MinigameWidget;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    EGymGamemode GymMode;
    UBaseGymMinigame(const FObjectInitializer& ObjectInitializer);
};
