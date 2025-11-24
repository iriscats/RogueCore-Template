#pragma once
#include "CoreMinimal.h"
#include "EEscortExtractorState.h"
#include "EscortMuleExtractorSlot.generated.h"

class UInstantUsable;
class USceneComponent;
class UWidgetComponent;
USTRUCT(BlueprintType)
struct FEscortMuleExtractorSlot {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EEscortExtractorState ExtractorState;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, NotReplicated, Transient, meta=(AllowPrivateAccess=true))
    EEscortExtractorState LastState;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, Transient, meta=(AllowPrivateAccess=true))
    USceneComponent* AttachPoint;
    UInstantUsable* usable;
    UWidgetComponent* Widget;
    ROGUECORE_API FEscortMuleExtractorSlot();
};
