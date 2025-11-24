#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "HealthBarLooks.generated.h"

USTRUCT(BlueprintType)
struct FHealthBarLooks {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FLinearColor HealthColor;
    
    FLinearColor DamageColor;
    ROGUECORE_API FHealthBarLooks();
};
