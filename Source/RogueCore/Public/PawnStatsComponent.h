#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "DamageRelevant.h"
#include "PawnStatEntriesArray.h"
#include "PawnStatsComponent.generated.h"

class UPawnStat;
UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class UPawnStatsComponent : public UActorComponent, public IDamageRelevant {
    GENERATED_BODY()
    // UPROPERTY fields moved from protected section

public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, ReplicatedUsing=Onrep_Stats, meta=(AllowPrivateAccess=true))
    FPawnStatEntriesArray Stats;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool UseDormancy;
    UPawnStatsComponent(const FObjectInitializer& ObjectInitializer);
    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
    UFUNCTION(BlueprintAuthorityOnly, BlueprintCallable)
    void RemoveModifier(UPawnStat* Stat, float Value);
    UFUNCTION(BlueprintCallable)
    void Onrep_Stats(const FPawnStatEntriesArray& oldStats);
    UFUNCTION(BlueprintCallable, BlueprintPure)
    float GetStatValue(const UPawnStat* Stat) const;
    void ChangeModifier(UPawnStat* Stat, float CurrentValue, float NewValue);
    int32 AddModifier(UPawnStat* Stat, float Value);
    // Fix for true pure virtual functions not being implemented
};
