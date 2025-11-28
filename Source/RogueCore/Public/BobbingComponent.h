#pragma once
#include "CoreMinimal.h"
#include "Components/SceneComponent.h"
#include "MovedIntoSomethingDelegate.h"
#include "BobbingComponent.generated.h"

class AActor;
UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class UBobbingComponent : public USceneComponent {
    GENERATED_BODY()
    
public:
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FMovedIntoSomething OnMovedIntoSomethingEvent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    USceneComponent* External;
 
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    AActor* OwnerActor;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool DoOrientationChecks;
    float BobSpeed;
    float BobSize;
    float OrentationChecksPerSecond;
    UBobbingComponent(const FObjectInitializer& ObjectInitializer);
    UFUNCTION(BlueprintCallable)
    void SetOwner(AActor* aActor);
};
