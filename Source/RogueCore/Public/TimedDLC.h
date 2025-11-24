#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "DLCBase.h"
#include "TimedDLC.generated.h"

UCLASS(Blueprintable)
class UTimedDLC : public UDLCBase {
    GENERATED_BODY()
    // UPROPERTY fields moved from protected section
public:

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FDateTime StartDate;
    
    FDateTime EndDate;
    UTimedDLC();
};
