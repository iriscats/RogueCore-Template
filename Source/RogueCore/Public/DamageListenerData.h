#pragma once
#include "CoreMinimal.h"
#include "EDamageVector.h"
#include "DamageListenerData.generated.h"

class AActor;
class UDamageClass;
class UDamageTag;
USTRUCT(BlueprintType)
struct FDamageListenerData {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EDamageVector DamageVector;
    
    UDamageClass* DamagType;
    TArray<UDamageTag*> DamageTags;
    AActor* Target;
    float ArmorDamage;
    float DamageDealt;
    float DamgeMultiplier;
    bool KillingBlow;
    bool Radial;
    ROGUECORE_API FDamageListenerData();
};
