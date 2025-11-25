#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "OxygenActiveDelegateDelegate.h"
#include "OxygenCallback.h"
#include "OxygenDelegateDelegate.h"
#include "OxygenTriggerDelegateDelegate.h"
#include "Templates/SubclassOf.h"
#include "OxygenComponent.generated.h"

class UHealthComponentBase;
class UStatusEffect;
UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class UOxygenComponent : public UActorComponent {
    GENERATED_BODY()
    // UPROPERTY fields moved from protected section

public:
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOxygenDelegate OnOxygenChanged;
    
    FOxygenActiveDelegate OnOxygenReplenishingEvent;
 
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float OxygenGivenOnRevive;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    float CurrentOxygen;
    float OxygenReplinishmentRate;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, ReplicatedUsing=OnRep_NetworkedOxygen, meta=(AllowPrivateAccess=true))
    int32 NetworkedOxygen;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, ReplicatedUsing=OnRep_IsReplenishingOxygen, meta=(AllowPrivateAccess=true))
    bool IsReplenishingOxygen;
    float OxygenDepletionPersecond;
    TArray<FOxygenCallback> Callbacks;
    TSubclassOf<UStatusEffect> NoOxygenStatusEffect;
    UOxygenComponent(const FObjectInitializer& ObjectInitializer);
    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
    UFUNCTION(BlueprintCallable)
    void RegisterOxygenEvent(FOxygenTriggerDelegate OxygenCallback, float oxygenLevel, bool triggerOnOxygenLoss);
    void OnRevived();
    UFUNCTION()
    void OnRep_NetworkedOxygen(int32 OldValue);
    UFUNCTION()
    void OnRep_IsReplenishingOxygen();
    void OnDeath(UHealthComponentBase* HealthComponent);
};
