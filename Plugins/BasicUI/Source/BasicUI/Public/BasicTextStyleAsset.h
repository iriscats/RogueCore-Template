#pragma once
#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "Styling/SlateTypes.h"
#include "BasicTextStyleAsset.generated.h"

UCLASS(Blueprintable)
class BASICUI_API UBasicTextStyleAsset : public UDataAsset {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FTextBlockStyle Style;
    
public:
    UBasicTextStyleAsset();

};

