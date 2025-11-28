#pragma once
#include "CoreMinimal.h"

#include "DamageParametersReport.generated.h"

class AActor;
class APawn;
class UDamageClass;
USTRUCT(BlueprintType)
struct FDamageParametersReport {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UDamageClass* DamageType;
    
    FVector Location;
    AActor* Target;
    AActor* Causer;
    APawn* Instigator;
    ROGUECORE_API FDamageParametersReport();
};
