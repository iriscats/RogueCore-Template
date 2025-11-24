#pragma once
#include "CoreMinimal.h"
#include "IRandRange.h"
#include "JettyBootNPC.generated.h"

USTRUCT(BlueprintType)
struct FJettyBootNPC {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FString CharacterName;
    
    float HasPlayedChance;
    FIRandRange ScoreInterval;
    TArray<int32> StartScores;
    ROGUECORE_API FJettyBootNPC();
};
