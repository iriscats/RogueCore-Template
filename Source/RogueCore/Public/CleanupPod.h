#pragma once
#include "CoreMinimal.h"
#include "ERessuplyPodState.h"
#include "RessuplyPod.h"
#include "CleanupPod.generated.h"

class UObjective;
class USphereComponent;
UCLASS(Blueprintable)
class ACleanupPod : public ARessuplyPod {
    GENERATED_BODY()
public:
    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Instanced, meta=(AllowPrivateAccess=true))
    USphereComponent* RemovePlagueCollision;
    
    ACleanupPod(const FObjectInitializer& ObjectInitializer);
 
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnObjectiveChanged(UObjective* Objective);
    UFUNCTION(BlueprintCallable)
    void ChangedState(ARessuplyPod* InPod, ERessuplyPodState InState);
};
