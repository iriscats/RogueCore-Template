#include "GameModeFunctionLibrary.h"

UGameModeFunctionLibrary::UGameModeFunctionLibrary() {
}

bool UGameModeFunctionLibrary::IsCloseToImportantLocation(AFSDGameState* GameState, const FVector& Location) {
    return false;
}

FTransform UGameModeFunctionLibrary::FindEscapePodLocationAtDistance(UObject* WorldContextObject, float Distance, float aboveDistanceBias, AActor* optionalFrom) {
    return FTransform{};
}

bool UGameModeFunctionLibrary::AreAllMissionEndResultsReceived(const UObject* WorldContext) {
    return false;
}

void UGameModeFunctionLibrary::AddSeamlessTravelEventKey(UObject* WorldContextObject, USeamlessTravelEventKey* Key) {
}


