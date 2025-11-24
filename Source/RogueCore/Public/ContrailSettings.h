#pragma once
#include "CoreMinimal.h"
#include "ContrailSettings.generated.h"

USTRUCT(BlueprintType)
struct FContrailSettings {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float Radius;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    float HalfLenght;
    float Lifetime;
    bool Hellfire;
    bool Electric;
    ROGUECORE_API FContrailSettings();
};
