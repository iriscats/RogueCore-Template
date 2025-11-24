#include "NamedCountdownLibrary.h"

UNamedCountdownLibrary::UNamedCountdownLibrary() {
}

void UNamedCountdownLibrary::StartNamedCountdownWithQuickFinish(const UObject* WorldContext, const FName Name, const int32 CountdownSeconds) {
}

void UNamedCountdownLibrary::StartNamedCountdown(const UObject* WorldContext, const FName Name, const int32 CountdownSeconds) {
}

void UNamedCountdownLibrary::ResetNamedCountdown(const UObject* WorldContext, const FName Name) {
}

ENamedCountdownState UNamedCountdownLibrary::GetNamedCountdownState(const UObject* WorldContext, const FName Name) {
    return ENamedCountdownState::NotStarted;
}

FNamedCountdownInt UNamedCountdownLibrary::GetNamedCountdown(const UObject* WorldContext, const FName Name) {
    return FNamedCountdownInt{};
}


