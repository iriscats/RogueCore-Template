#pragma once
#include "CoreMinimal.h"
#include "Components/SceneComponent.h"
#include "EDroneActions.h"
#include "DroneDisplayActionComponent.generated.h"

class UTextRenderComponent;
UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class UDroneDisplayActionComponent : public USceneComponent {
    GENERATED_BODY()
    

public:

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UTextRenderComponent* DisplayText;
    
    UDroneDisplayActionComponent(const FObjectInitializer& ObjectInitializer);
    UFUNCTION(BlueprintCallable)
    void SetMode(EDroneActions droneAction);
};
