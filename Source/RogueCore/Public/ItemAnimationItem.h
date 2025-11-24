#pragma once
#include "CoreMinimal.h"
#include "ItemAnimationItem.generated.h"

class UAnimMontage;
USTRUCT(BlueprintType)
struct FItemAnimationItem {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UAnimMontage* FP_CharacterMontage;
    
    UAnimMontage* TP_CharacterMontage;
    UAnimMontage* ItemMontage;
    ROGUECORE_API FItemAnimationItem();
};
