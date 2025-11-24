#pragma once
#include "CoreMinimal.h"
#include "ETagEffectTarget.h"
#include "TagEffectBase.h"
#include "Templates/SubclassOf.h"
#include "TagStatusEffect.generated.h"

class UStatusEffect;
UCLASS(Blueprintable, EditInlineNew)
class UTagStatusEffect : public UTagEffectBase {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<UStatusEffect> StatusEffect;
    
    ETagEffectTarget Target;
    UTagStatusEffect();
};
