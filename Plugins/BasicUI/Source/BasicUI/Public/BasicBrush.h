#pragma once
#include "CoreMinimal.h"
#include "Styling/SlateBrush.h"
#include "BasicBrush.generated.h"

class UBasicBrushAsset;

USTRUCT(BlueprintType)
struct BASICUI_API FBasicBrush {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bFromAsset;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UBasicBrushAsset* Asset;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSlateBrush Value;
    
public:
    FBasicBrush();
};

