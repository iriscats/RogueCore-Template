#pragma once
#include "CoreMinimal.h"
#include "ItemAquisitionBase.h"
#include "DLCAquisition.generated.h"

class UDLCBase;
UCLASS(Blueprintable, EditInlineNew)
class ROGUECORE_API UDLCAquisition : public UItemAquisitionBase {
    GENERATED_BODY()
    // UPROPERTY fields moved from protected section

public:

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UDLCBase* RequiredDLC;
    
    UDLCAquisition();
};
