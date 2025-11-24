#pragma once
#include "CoreMinimal.h"
#include "StatusEffectItem.h"
#include "StatChangeStatusEffectItem.generated.h"

class UObject;
class UPawnStat;
class UStatusEffect;
UCLASS(Blueprintable, EditInlineNew)
class UStatChangeStatusEffectItem : public UStatusEffectItem {
    GENERATED_BODY()
    // UPROPERTY fields moved from protected section

public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UPawnStat* Stat;
    
    float StatChange;
    bool AffectedByResistances;
    UStatChangeStatusEffectItem();
    UFUNCTION(BlueprintCallable)
    static UStatusEffect* CreateStatSTE(UObject* Owner, UPawnStat* PawnStat, float StartingValue);
};
