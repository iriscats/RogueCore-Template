#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "DelegateEventDelegate.h"
#include "ObjectivesManager.generated.h"

class UDialogDataAsset;
class UObjective;
UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class UObjectivesManager : public UActorComponent {
    GENERATED_BODY()
    // UPROPERTY fields moved from protected section

public:
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FDelegateEvent OnObjectivesCompleted;
    
    UPROPERTY(BlueprintAssignable, BlueprintCallable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FDelegateEvent OnObjectivesChanged;
    FDelegateEvent OnAllRequiredReturnObjectivesCompleted;
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, Transient, meta=(AllowPrivateAccess=true))
    UObjective* Objective;
    TArray<UObjective*> SecondaryObjectives;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float CompletionRequirement;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    bool ObjectivesInitialized;
    bool ObjectivesStarted;
    bool bCheatObjectivesCompleted;
    UObjectivesManager(const FObjectInitializer& ObjectInitializer);
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool ReturnObjectivesCompleted(bool& hasRequiredSecondary, UDialogDataAsset*& OverridePrimaryObjCompletedShout) const;
    UFUNCTION(BlueprintCallable)
    void OnObjectiveChanged(UObjective* obj);
    bool HasRequiredSecondaryObjective() const;
    UObjective* GetSecondaryObjective() const;
    UObjective* GetPrimaryObjective() const;
    TArray<UObjective*> GetAllSecondaryObjectives() const;
    void ExitPodDescending();
    void ExitPodArrived();
    void DropPodExited();
    bool AreRequiredSecondariesComplete() const;
};
