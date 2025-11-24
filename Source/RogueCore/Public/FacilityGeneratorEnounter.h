#pragma once
#include "CoreMinimal.h"
#include "RandInterval.h"
#include "FacilityGeneratorEnounter.generated.h"

class UEnemyDescriptor;
USTRUCT(BlueprintType)
struct FFacilityGeneratorEnounter {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<UEnemyDescriptor*> Enemies;
    
    float Difficulty;
    FRandInterval Diversity;
    ROGUECORE_API FFacilityGeneratorEnounter();
};
