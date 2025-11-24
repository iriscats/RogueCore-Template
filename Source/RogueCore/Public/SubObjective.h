#pragma once
#include "CoreMinimal.h"
#include "SubObjective.generated.h"

class UDialogDataAsset;
USTRUCT(BlueprintType)
struct FSubObjective {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UDialogDataAsset* OnProgressShout;
    
    UDialogDataAsset* OnCompletedShout;
    FText ObjectiveText;
    int32 Required;
    int32 count;
    ROGUECORE_API FSubObjective();
};
