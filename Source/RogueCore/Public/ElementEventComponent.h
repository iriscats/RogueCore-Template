#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "ElementEventState.h"
#include "ElementEventComponent.generated.h"

class AActor;
class UElementEventType;
class UElementType;
UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class UElementEventComponent : public UActorComponent {
    GENERATED_BODY()
    

public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UElementEventType* EventType;
    
    UElementType* TriggeredByElementType;
    AActor* Source;
    UElementEventComponent(const FObjectInitializer& ObjectInitializer);
 
    UFUNCTION(BlueprintCallable)
    bool FindEventState(FElementEventState& EventState);
};
