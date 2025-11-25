#pragma once
#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "BasicPanelSize.h"
#include "BasicPanelFunctionLibrary.generated.h"

class USizeBox;

UCLASS(Blueprintable)
class UBasicPanelFunctionLibrary : public UBlueprintFunctionLibrary {
    GENERATED_BODY()
public:
    UBasicPanelFunctionLibrary();

 
    UFUNCTION(BlueprintCallable)
    static void ApplySizeBoxSettings(USizeBox* InSizeBox, FBasicPanelSize InSizeSettings);
    
};

