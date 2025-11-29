#pragma once
#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "BXEDifficultyPoint.h"
#include "StageDifficultyProgression.generated.h"

class URun;
UCLASS(Blueprintable)
class UStageDifficultyProgression : public UDataAsset {
    GENERATED_BODY()
    

public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FBXEDifficultyPoint> Difficulties;
    
    UStageDifficultyProgression();
    UFUNCTION(BlueprintCallable)
    static float GetTimePerPoint(const FBXEDifficultyPoint& InPoint, int32 InPlayerCount, const URun* Run);
    FBXEDifficultyPoint GetDifficultyAtTime(float TimeSeconds, int32 PlayerCount, const URun* Run);
    UFUNCTION(BlueprintCallable, BlueprintPure)
    TArray<FBXEDifficultyPoint> GetDifficulties() const;
};
