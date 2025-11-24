#include "PlayerCharacterFunctionLibrary.h"

UPlayerCharacterFunctionLibrary::UPlayerCharacterFunctionLibrary() {
}

bool UPlayerCharacterFunctionLibrary::SetPlayerVoiceMuted(UObject* WorldContextObject, AFSDPlayerState* PlayerState, bool Mute, bool TrySystemWide, int32 LocalUserNum) {
    return false;
}

bool UPlayerCharacterFunctionLibrary::IsPlayerVoiceMuted(UObject* WorldContextObject, AFSDPlayerState* PlayerState, int32 LocalUserNum) {
    return false;
}

APlayerCharacter* UPlayerCharacterFunctionLibrary::GetRandomPlayer(UObject* WorldContextObject, bool MustBeAlive, bool MustNotBeParalyzed, const bool IgnoreIncapacitated) {
    return NULL;
}

APlayerCharacter* UPlayerCharacterFunctionLibrary::GetNearestVisiblePlayer(AActor* From, float MaxDistance, bool MustBeAlive, bool MustNotBeParalyzed, const bool IgnoreIncapacitated) {
    return NULL;
}

APlayerCharacter* UPlayerCharacterFunctionLibrary::GetNearestPlayerToPosition(UObject* WorldContextObject, FVector position, float MaxDistance, bool MustBeAlive, bool MustBeUnparalyzed, const bool IgnoreIncapacitated, bool XYOnly) {
    return NULL;
}

APlayerCharacter* UPlayerCharacterFunctionLibrary::GetNearestPlayerFrom(UObject* WorldContext, FVector From, float MaxDistance, bool MustBeAlive, bool MustBeUnparalyzed, const bool IgnoreIncapacitated, bool XYOnly) {
    return NULL;
}

APlayerCharacter* UPlayerCharacterFunctionLibrary::GetNearestPlayer(AActor* From, float MaxDistance, bool MustBeAlive, bool MustBeUnparalyzed, const bool IgnoreIncapacitated, bool XYOnly) {
    return NULL;
}


