#pragma once
#include "CoreMinimal.h"
#include "ERunItemOverrideType.h"
#include "ERunListOverrideType.h"
#include "RunMutatorOverrides.generated.h"

class UMutator;
class UPrimaryMutator;
class URiskVector;
USTRUCT(BlueprintType)
struct FRunMutatorOverrides {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    ERunItemOverrideType PrimaryMutatorOverride;
    
    UPrimaryMutator* PrimaryMutator;
    ERunListOverrideType SecondaryMutatorsOverride;
    TArray<UMutator*> SecondaryMutators;
    ERunListOverrideType RiskVectorsOverride;
    TArray<URiskVector*> RiskVectors;
    ROGUECORE_API FRunMutatorOverrides();
};
