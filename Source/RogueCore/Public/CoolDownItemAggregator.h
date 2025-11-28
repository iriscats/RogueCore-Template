#pragma once
#include "CoreMinimal.h"
#include "ItemAggregator.h"
#include "CoolDownItemAggregator.generated.h"

class AItem;
class USoundBase;
UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class UCoolDownItemAggregator : public UItemAggregator {
    GENERATED_BODY()
    

public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float CooldownDuration;
    
    USoundBase* AudioCoolDownFinished;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    float CooldownRemaining;
    bool CoolDownIsPaused;
    AItem* Item;
    UCoolDownItemAggregator(const FObjectInitializer& ObjectInitializer);
    UFUNCTION(BlueprintCallable)
    void SetPaused(bool IsPaused);
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsCoolingDown() const;
    float GetCoolDownProgress() const;
    void ActivateCoolDown(bool startPaused);
};
