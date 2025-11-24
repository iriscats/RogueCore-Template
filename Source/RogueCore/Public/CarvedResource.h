#pragma once
#include "CoreMinimal.h"
#include "CarvedResource.generated.h"

class UCarvedResourceCreator;
USTRUCT(BlueprintType)
struct FCarvedResource {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, Transient, meta=(AllowPrivateAccess=true))
    UCarvedResourceCreator* ResourceCreator;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TArray<int32> PredeterminedRooms;
    int32 amount;
    float Overflow;
    ROGUECORE_API FCarvedResource();
};
