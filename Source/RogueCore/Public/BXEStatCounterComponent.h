#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "DelegateDelegate.h"
#include "RejoinListener.h"
#include "BXEStatCounterComponent.generated.h"

class APlayerCharacter;
class UPawnStat;
UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class UBXEStatCounterComponent : public UActorComponent, public IRejoinListener {
    GENERATED_BODY()
    // UPROPERTY fields moved from protected section
public:
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FDelegate OnStatsUpdated;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FText TotalDamageDealtText;
    FText TotalDamageTakenText;
    FText HealthText;
    FText ShieldText;
    TSet<UPawnStat*> AlwaysShownStats;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TSet<UPawnStat*> ActiveStats;
    APlayerCharacter* Character;
    UBXEStatCounterComponent(const FObjectInitializer& ObjectInitializer);
    UFUNCTION(BlueprintCallable)
    void OnPlayerHealthChanged(float Health);
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FText GetStatsTextForUI() const;
    // Fix for true pure virtual functions not being implemented
};
