#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "RichIconRow.generated.h"

class UTexture2D;
USTRUCT(BlueprintType)
struct FRichIconRow {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UTexture2D* Icon;
    
    FLinearColor IconTint;
    FText ToolTip;
    ROGUECORE_API FRichIconRow();
};
