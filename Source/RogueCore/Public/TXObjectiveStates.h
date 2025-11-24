#pragma once
#include "CoreMinimal.h"
#include "TXObjectiveStates.generated.h"

USTRUCT(BlueprintType)
struct FTXObjectiveStates {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FString Name;
    
    FString State;
    ROGUECORE_API FTXObjectiveStates();
};
