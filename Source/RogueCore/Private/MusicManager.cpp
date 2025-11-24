#include "MusicManager.h"

UMusicManager::UMusicManager() {
}

void UMusicManager::StopTransitionMusic(float FadeOut) {
}

void UMusicManager::StopHandle(FMusicHandle Handle) {
}

void UMusicManager::StopCategory(UMusicCategory* Category) {
}

void UMusicManager::StopAllMusic() {
}

void UMusicManager::SetIsPaused(bool IsPaused) {
}

void UMusicManager::PlayTransitionMusic(USoundBase* Music, float FadeIn) {
}

FMusicHandle UMusicManager::PlayLibrary(UMusicLibrary* Library, int32 musicIndex) {
    return FMusicHandle{};
}

FMusicHandle UMusicManager::Play(USoundBase* Music, UMusicCategory* Category) {
    return FMusicHandle{};
}

bool UMusicManager::IsTransitionMusicPlaying() const {
    return false;
}


