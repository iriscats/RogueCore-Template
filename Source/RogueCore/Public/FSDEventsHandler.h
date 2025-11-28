#pragma once
#include "CoreMinimal.h"

#include "UObject/Object.h"
#include "FSDEventsHandler.generated.h"

UCLASS(Blueprintable)
class UFSDEventsHandler : public UObject {
    GENERATED_BODY()
    // UPROPERTY fields moved from private section
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    FDateTime LastRequestTime;
    
 
    int32 NumFailedRequests;
    UFSDEventsHandler();
};
