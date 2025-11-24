#pragma once
#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "InputCoreTypes.h"
#include "KeyStrokeMatcher.h"
#include "KeyStrokeMatcherLibrary.generated.h"

UCLASS(Blueprintable)
class UKeyStrokeMatcherLibrary : public UBlueprintFunctionLibrary {
    GENERATED_BODY()
public:
    UKeyStrokeMatcherLibrary();
private:
    UFUNCTION(BlueprintCallable)
    static bool TestKeyStroke(UPARAM(Ref) FKeyStrokeMatcher& KeyStrokeMatcher, const FKeyEvent& InKey);
    
    static void ReleaseKeyStroke(UPARAM(Ref) FKeyStrokeMatcher& KeyStrokeMatcher, const FKeyEvent& InKey);
};
