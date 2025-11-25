#pragma once
#include "CoreMinimal.h"
#include "EnemyLineOfSightComponent.h"
#include "TentacleBusyComponent.generated.h"

class AActor;
UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class UTentacleBusyComponent : public UEnemyLineOfSightComponent {
    GENERATED_BODY()
public:
    UTentacleBusyComponent(const FObjectInitializer& ObjectInitializer);
 
    UFUNCTION(BlueprintCallable)
    void ReleasedActor(AActor* Escape, bool fullGrab);
    
    void GrabbedActor(AActor* victim);
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool GetIsBusy() const;
};
