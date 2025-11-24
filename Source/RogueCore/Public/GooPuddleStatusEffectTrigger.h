#pragma once
#include "CoreMinimal.h"
#include "Templates/SubclassOf.h"
#include "GooPuddleStatusEffectTrigger.generated.h"

class UDamageClass;
class UStatusEffect;
USTRUCT(BlueprintType)
struct FGooPuddleStatusEffectTrigger {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<UDamageClass*> Trigger;
    
    TSubclassOf<UStatusEffect> NewStatusEffect;
    ROGUECORE_API FGooPuddleStatusEffectTrigger();
};
