#pragma once
#include "CoreMinimal.h"
#include "CSGOption.h"
#include "CSGOptions.generated.h"

USTRUCT(BlueprintType)
struct ROGUECOREENGINE_API FCSGOptions {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FCSGOption> Pairs;
    
    FCSGOptions();
};

