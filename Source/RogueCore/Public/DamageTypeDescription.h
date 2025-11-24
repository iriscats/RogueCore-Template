#pragma once
#include "CoreMinimal.h"
#include "EDamageType.h"
#include "SoftIconWithColor.h"
#include "DamageTypeDescription.generated.h"

USTRUCT(BlueprintType)
struct FDamageTypeDescription {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EDamageType Type;
    
    FText Name;
    FText RichDescription;
    FSoftIconWithColor Icon;
    float IconScale;
    ROGUECORE_API FDamageTypeDescription();
};
