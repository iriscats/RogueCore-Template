#pragma once
#include "CoreMinimal.h"
#include "EKeyStrokeMatcherMode.h"
#include "KeyStrokeMatcher.generated.h"

USTRUCT(BlueprintType)
struct FKeyStrokeMatcher {
    GENERATED_BODY()
    // UPROPERTY fields moved from protected section
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EKeyStrokeMatcherMode Mode;
    
    TArray<FKey> Keys;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TArray<bool> Pressed;
    ROGUECORE_API FKeyStrokeMatcher();
};
