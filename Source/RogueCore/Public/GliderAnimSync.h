#pragma once
#include "CoreMinimal.h"

#include "GliderAnimSync.generated.h"

USTRUCT(BlueprintType)
struct FGliderAnimSync {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    float Time;
    
    float AnimAlphaSync;
    FVector VelocityPercent;
    bool DownUpBlendBool;
    bool RightLeftBlendBool;
    float VerticalAddBlend;
    float HorizontalAddBlend;
    ROGUECORE_API FGliderAnimSync();
};
