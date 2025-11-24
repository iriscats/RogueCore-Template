#pragma once
#include "CoreMinimal.h"
#include "CaveInfluence.h"
#include "GeneratedInfluenceSet.generated.h"

class UObject;
USTRUCT(BlueprintType)
struct FGeneratedInfluenceSet {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    UObject* CaveInfluencer;
    
    int32 NetworkID;
    TArray<FCaveInfluence> CaveInfluences;
    ROGUECORE_API FGeneratedInfluenceSet();
};
