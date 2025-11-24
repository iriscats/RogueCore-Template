#include "StageDifficultyProgression.h"

UStageDifficultyProgression::UStageDifficultyProgression() {
}

float UStageDifficultyProgression::GetTimePerPoint(const FBXEDifficultyPoint& InPoint, int32 InPlayerCount, const URun* Run) {
    return 0.0f;
}

FBXEDifficultyPoint UStageDifficultyProgression::GetDifficultyAtTime(float TimeSeconds, int32 PlayerCount, const URun* Run) {
    return FBXEDifficultyPoint{};
}

TArray<FBXEDifficultyPoint> UStageDifficultyProgression::GetDifficulties() const {
    return TArray<FBXEDifficultyPoint>();
}


