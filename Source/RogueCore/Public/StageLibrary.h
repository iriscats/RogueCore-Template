#pragma once
#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "AsyncLoadCompleteDelegateDelegate.h"
#include "StageLibrary.generated.h"

class UStage;
UCLASS(Blueprintable)
class ROGUECORE_API UStageLibrary : public UBlueprintFunctionLibrary {
    GENERATED_BODY()
public:
    UStageLibrary();
    UFUNCTION(BlueprintCallable)
    static void PreloadStageAssets(const UStage* Stage, const FAsyncLoadCompleteDelegate& OnLoadComplete);
    
};
