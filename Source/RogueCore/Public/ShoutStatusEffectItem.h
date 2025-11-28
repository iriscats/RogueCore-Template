#pragma once
#include "CoreMinimal.h"
#include "StatusEffectItem.h"
#include "ShoutStatusEffectItem.generated.h"

class UDialogDataAsset;
UCLASS(Blueprintable, EditInlineNew)
class UShoutStatusEffectItem : public UStatusEffectItem {
    GENERATED_BODY()
    

public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UDialogDataAsset* BeginShout;
    
    UShoutStatusEffectItem();
};
