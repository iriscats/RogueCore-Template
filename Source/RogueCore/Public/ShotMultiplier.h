#pragma once
#include "CoreMinimal.h"
#include "ShotMultiplier.generated.h"

USTRUCT(BlueprintType)
struct FShotMultiplier {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    float Undercharge;
    
    float Overcharge;
    bool TriBurst;
    ROGUECORE_API FShotMultiplier();
};
