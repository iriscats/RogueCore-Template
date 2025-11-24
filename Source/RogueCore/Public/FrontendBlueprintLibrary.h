#pragma once
#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "EFSDTargetPlatform.h"
#include "FrontendBlueprintLibrary.generated.h"

UCLASS(Blueprintable)
class UFrontendBlueprintLibrary : public UBlueprintFunctionLibrary {
    GENERATED_BODY()
public:
    UFrontendBlueprintLibrary();
    UFUNCTION(BlueprintCallable)
    static void OpenURLInExternalBrowser(const FString& URL);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static bool IsShippingBuild();
    static void GetStringFromClipboard(FString& fromClipboard);
    static bool FSDTargetPlatformIsXSX();
    static EFSDTargetPlatform FSDTargetPlatform();
    static void CopyStringToClipboard(const FString& toClipboard);
};
