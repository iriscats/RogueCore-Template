#pragma once
#include "CoreMinimal.h"
#include "DamageBonusBase.h"
#include "Templates/SubclassOf.h"
#include "LockCountSTEBonus.generated.h"

class UStatusEffect;
UCLASS(Blueprintable, EditInlineNew)
class ULockCountSTEBonus : public UDamageBonusBase {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 MinLockCount;
    
    bool UseTotalLockCount;
    TSubclassOf<UStatusEffect> StatusEffect;
    ULockCountSTEBonus();
};
