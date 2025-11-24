#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Components/ActorComponent.h"
#include "PuddleTrackerComponent.generated.h"

class AActor;
UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class UPuddleTrackerComponent : public UActorComponent {
    GENERATED_BODY()
public:
    UPuddleTrackerComponent(const FObjectInitializer& ObjectInitializer);
protected:
    UFUNCTION(BlueprintCallable)
    void OnPuddleDestroyed(AActor* DestroyedActor);
    
    void GetPuddles(TArray<AActor*>& Locations);
    void GetPuddleLocations(TArray<FVector>& Locations);
    void AddPuddle(AActor* puddle);
};
