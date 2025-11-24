#pragma once
#include "CoreMinimal.h"
#include "TestUnlocksContainer.h"
#include "TestNegotiationContainer.generated.h"

USTRUCT(BlueprintType)
struct FTestNegotiationContainer {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FTestUnlocksContainer> negotiations;
    
    ROGUECORE_API FTestNegotiationContainer();
};
