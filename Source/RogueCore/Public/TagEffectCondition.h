#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "TagEffectCondition.generated.h"

UCLASS(Blueprintable)
class UTagEffectCondition : public UObject {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool Invert;
    
    UTagEffectCondition();
};
