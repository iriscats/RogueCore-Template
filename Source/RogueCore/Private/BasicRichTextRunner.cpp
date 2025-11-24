#include "BasicRichTextRunner.h"

UBasicRichTextRunner::UBasicRichTextRunner() {
    this->TextStyleSet = NULL;
    this->Progress = 1.00f;
    this->InternalRichText = NULL;
}

void UBasicRichTextRunner::SetTextStyleSet(UDataTable* NewTextStyleSet) {
}

void UBasicRichTextRunner::SetText(FText InText) {
}

void UBasicRichTextRunner::SetProgress(float InProgress) {
}

UDataTable* UBasicRichTextRunner::GetTextStyleSet() const {
    return NULL;
}

float UBasicRichTextRunner::GetProgress() const {
    return 0.0f;
}


