#pragma once
#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "ElementCondition.generated.h"

UCLASS(Abstract, Blueprintable, DefaultToInstanced, EditInlineNew)
class ROGUECORE_API UElementCondition : public UDataAsset
{
    GENERATED_BODY()

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool Invert;

public:
    UElementCondition();
};