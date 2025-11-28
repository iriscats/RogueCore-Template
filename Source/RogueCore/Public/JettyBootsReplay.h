#pragma once
#include "CoreMinimal.h"

#include "JettyBootsReplay.generated.h"

USTRUCT(BlueprintType)
struct FJettyBootsReplay {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 Seed;
    
    FVector2D position;
    uint8 State;
    int32 Level;
    int32 score;
    int32 Lives;
    ROGUECORE_API FJettyBootsReplay();
};
