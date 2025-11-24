#pragma once
#include "CoreMinimal.h"
#include "DamageModifierItem.h"
#include "BXEDamageUnlockModifiers.generated.h"

USTRUCT(BlueprintType)
struct FBXEDamageUnlockModifiers {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FDamageModifierItem> ModifierItems;
    
    ROGUECORE_API FBXEDamageUnlockModifiers();
};
