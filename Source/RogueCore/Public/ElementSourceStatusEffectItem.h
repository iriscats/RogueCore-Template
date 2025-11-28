#pragma once
#include "CoreMinimal.h"
#include "EElementSourceIntensity.h"
#include "StatusEffectItem.h"
#include "ElementSourceStatusEffectItem.generated.h"

class UElementType;
UCLASS(Blueprintable, EditInlineNew)
class UElementSourceStatusEffectItem : public UStatusEffectItem {
    GENERATED_BODY()
    

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UElementType* ElementType;

    float Value;

    EElementSourceIntensity Intensity;

public:
    UElementSourceStatusEffectItem();
};
