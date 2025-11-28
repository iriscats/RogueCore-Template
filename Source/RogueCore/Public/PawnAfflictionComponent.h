#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AfflictionChangeDelegateDelegate.h"
#include "AfflictionEntriesArray.h"
#include "EFrozenBitsSize.h"
#include "IRandRange.h"
#include "PawnAfflictionItem.h"
#include "Templates/SubclassOf.h"
#include "PawnAfflictionComponent.generated.h"

class UAfflictionEffect;
class UBurningAfflictionEffect;
class UHealthComponentBase;
class UPawnAffliction;
UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class UPawnAfflictionComponent : public UActorComponent {
    GENERATED_BODY()
    

public:
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FAfflictionChangeDelegate OnAfflictionActivatedEvent;
    
    FAfflictionChangeDelegate OnAfflictionDeactivatedEvent;
 
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TMap<UPawnAffliction*, FPawnAfflictionItem> ActiveAfflictions;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Replicated, Transient, meta=(AllowPrivateAccess=true))
    FAfflictionEntriesArray NetworkedAfflictions;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<UAfflictionEffect> FrozenEffect;
    TSubclassOf<UBurningAfflictionEffect> BurningEffect;
    EFrozenBitsSize EffectSize;
    FIRandRange FrozenBitsAmount;
    float FrozenBitsMinDistance;
    float BaseEffectScale;
    bool UseDormancy;
    UPawnAfflictionComponent(const FObjectInitializer& ObjectInitializer);
    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
    UFUNCTION(BlueprintAuthorityOnly, BlueprintCallable)
    void PushAffliction(UPawnAffliction* Affliction, bool onlyIfNotActive);
    void PopAffliction(UPawnAffliction* Affliction);
    UFUNCTION(BlueprintCallable)
    void OnDeath(UHealthComponentBase* HealthComponent);
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsAfflictedBy(UPawnAffliction* Affliction) const;
    TArray<UPawnAffliction*> GetActiveAfflictions() const;
};
