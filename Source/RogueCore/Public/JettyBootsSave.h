#pragma once
#include "CoreMinimal.h"
#include "JettyBootsScore.h"
#include "JettyBootsSave.generated.h"

USTRUCT(BlueprintType)
struct FJettyBootsSave {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FJettyBootsScore> HighScores;
    
    TArray<FJettyBootsScore> NPC_HighScores;
    bool bInitializeNPCs;
    int32 LastHighScoreIndex;
    ROGUECORE_API FJettyBootsSave();
};
