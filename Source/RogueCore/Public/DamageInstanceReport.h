#pragma once
#include "CoreMinimal.h"
#include "EDamageMethod.h"
#include "DamageInstanceReport.generated.h"

class UDamageClass;
class UDamageTag;
USTRUCT(BlueprintType)
struct FDamageInstanceReport {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UDamageClass* DamageType;
    
    TArray<UDamageTag*> DamageTags;
    float Damage;
    EDamageMethod Method;
    float Radius;
    ROGUECORE_API FDamageInstanceReport();
};
