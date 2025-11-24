#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AttackerManagerComponent.generated.h"

class UAttackerPositioningComponent;
UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class UAttackerManagerComponent : public UActorComponent {
    GENERATED_BODY()
    // UPROPERTY fields moved from protected section


public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, Transient, meta=(AllowPrivateAccess=true))
    TArray<UAttackerPositioningComponent*> Components;
    
    UAttackerManagerComponent(const FObjectInitializer& ObjectInitializer);
};
