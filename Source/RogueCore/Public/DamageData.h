#pragma once
#include "CoreMinimal.h"
#include "DamageDataBase.h"
#include "EDamageVector.h"
#include "ElementParams.h"
#include "DamageData.generated.h"

class AActor;
class AController;
class UDamageClass;
USTRUCT(BlueprintType)
struct FDamageData : public FDamageDataBase {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    EDamageVector DamageVector;
    
    UDamageClass* DamageClass;
    TWeakObjectPtr<AController> Instigator;
    TWeakObjectPtr<AActor> DamageCauser;
    float DamageModifier;
    float ArmorPenetration;
    FElementParams ElementParams;
    ROGUECORE_API FDamageData();
};
