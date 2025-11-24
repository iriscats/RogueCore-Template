#pragma once
#include "CoreMinimal.h"
#include "TXObjectiveStates.h"
#include "TXOngoingGameevents.generated.h"

USTRUCT(BlueprintType)
struct FTXOngoingGameevents {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool is_elevator_called;
    
    bool is_risk_vector_screen;
    int32 time_since_last_negotiation;
    TArray<FTXObjectiveStates> objective_states;
    ROGUECORE_API FTXOngoingGameevents();
};
