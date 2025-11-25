#pragma once
#include "CoreMinimal.h"
#include "Styling/SlateTypes.h"
#include "BasicTextStyle.generated.h"

class UBasicTextStyleAsset;

USTRUCT(BlueprintType)
struct BASICUI_API FBasicTextStyle {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bFromAsset;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UBasicTextStyleAsset* Asset;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FTextBlockStyle Value;
    
public:
    FBasicTextStyle();
};

