#pragma once
#include "CoreMinimal.h"

#include "SoftIconWithColor.generated.h"

class UTexture2D;
USTRUCT(BlueprintType)
struct FSoftIconWithColor {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSoftObjectPtr<UTexture2D> Icon;
    
    FLinearColor Tint;
    ROGUECORE_API FSoftIconWithColor();
};
