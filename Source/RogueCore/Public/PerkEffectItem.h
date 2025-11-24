#pragma once
#include "CoreMinimal.h"
#include "PerkEffectItem.generated.h"

class UBXEUnlockAction;
class UPerkEffect;
USTRUCT(BlueprintType)
struct FPerkEffectItem {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UBXEUnlockAction* Action;
    
    UPerkEffect* Effect;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FText Text;
    float Value;
    ROGUECORE_API FPerkEffectItem();
};
