#pragma once
#include "CoreMinimal.h"
#include "SpriteRect.generated.h"

USTRUCT(BlueprintType)
struct FSpriteRect {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float Left;
    
    float Top;
    float Right;
    float Bottom;
    ROGUECORE_API FSpriteRect();
};
