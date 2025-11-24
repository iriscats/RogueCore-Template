#include "MediaPlayerWidget.h"

UMediaPlayerWidget::UMediaPlayerWidget() : UUserWidget(FObjectInitializer::Get()) {
    this->MediaSource = NULL;
    this->MediaTexture = NULL;
    this->MediaSoundClass = NULL;
    this->VolumeMultiplier = 1.00f;
    this->PlayerState = EMediaPlayerState::Stopped;
    this->OutputImage = NULL;
}

void UMediaPlayerWidget::Stop() {
}


bool UMediaPlayerWidget::Play() {
    return false;
}

void UMediaPlayerWidget::Callback_MediaPlayResumed() {
}

void UMediaPlayerWidget::Callback_MediaOpened(const FString& URL) {
}

void UMediaPlayerWidget::Callback_MediaEndReached() {
}

void UMediaPlayerWidget::Callback_MediaClosed() {
}


