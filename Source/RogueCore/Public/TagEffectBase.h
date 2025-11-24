#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "TagEffectBase.generated.h"

class UTagEffectCondition;
UCLASS(Blueprintable)
class UTagEffectBase : public UObject {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    TArray<UTagEffectCondition*> Conditions;
    
    UTagEffectBase();
};
