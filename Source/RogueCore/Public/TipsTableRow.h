#pragma once
#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "TipsTableRow.generated.h"

USTRUCT(BlueprintType)
struct FTipsTableRow : public FTableRowBase {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FText Header;
    
    FText Description;
    FText InputText;
    FText InputTextControllerOverride;
    float TimeToDisplay;
    ROGUECORE_API FTipsTableRow();
};
