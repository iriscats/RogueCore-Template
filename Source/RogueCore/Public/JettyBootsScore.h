#pragma once
#include "CoreMinimal.h"
#include "JettyBootsScore.generated.h"

USTRUCT(BlueprintType)
struct FJettyBootsScore {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FString PlayerName;
    
    int32 score;
    ROGUECORE_API FJettyBootsScore();
};
