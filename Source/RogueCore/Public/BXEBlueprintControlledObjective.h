#pragma once
#include "CoreMinimal.h"
#include "Objective.h"
#include "BXEBlueprintControlledObjective.generated.h"

class AActor;
class UCurveFloat;
UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class ROGUECORE_API UBXEBlueprintControlledObjective : public UObjective {
    GENERATED_BODY()
    

public:
    UPROPERTY(EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TArray<TWeakObjectPtr<AActor>> SpawnedObjectiveActors;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UCurveFloat* DBAAvoidCostCurve;
    float BaseExpenitePayout;
    float SeenRange;
    float SeenUpdateRateSeconds;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, ReplicatedUsing=OnRep_ObjectiveCompleted, meta=(AllowPrivateAccess=true))
    bool ObjectiveCompleted;
    bool ObjectiveShouldSpawnXP;
    bool AllowDecoration;
    UBXEBlueprintControlledObjective(const FObjectInitializer& ObjectInitializer);
    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
    UFUNCTION(BlueprintCallable)
    void SetObjectiveCompleted();
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void Receive_AddEnemies();
    UFUNCTION()
    void OnRep_ObjectiveCompleted();
    UFUNCTION(BlueprintCallable, BlueprintPure)
    TArray<AActor*> GetSpawnedObjectiveActors() const;
    float GetExpenitePayout() const;
    void AddSpawnedObjectiveActors(const TArray<AActor*>& InSpawned);
    void AddSpawnedObjectiveActor(AActor* InSpawned);
};
