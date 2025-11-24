#pragma once
#include "CoreMinimal.h"
#include "Subsystems/WorldSubsystem.h"
#include "EObjectiveFailReason.h"
#include "EObjectiveState.h"
#include "BXEObjectiveTrackerSubSystem.generated.h"

class AActor;
class UBXEBlueprintControlledObjective;
UCLASS(Blueprintable)
class UBXEObjectiveTrackerSubSystem : public UWorldSubsystem {
    GENERATED_BODY()
public:
    UBXEObjectiveTrackerSubSystem();
    UFUNCTION(BlueprintCallable)
    bool UpdateObjectiveState(UBXEBlueprintControlledObjective* InObjective, EObjectiveState InState);
    
    void UpdateObjectiveFailReason(UBXEBlueprintControlledObjective* InObjective, EObjectiveFailReason InReason);
    void RegisterObjective(UBXEBlueprintControlledObjective* InObjective);
    void RecordExpeniteTarget(UBXEBlueprintControlledObjective* InObjective, float InAmount);
    void RecordExpeniteSpawned(UBXEBlueprintControlledObjective* InObjective, float InAmount);
    void RecordExpeniteReceived(UBXEBlueprintControlledObjective* InObjective, float InAmount);
    UFUNCTION(BlueprintCallable, BlueprintPure)
    UBXEBlueprintControlledObjective* FindObjectiveFromActor(const AActor* InObjectiveActor) const;
};
