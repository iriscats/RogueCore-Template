#include "RichTextSizable.h"

URichTextSizable::URichTextSizable() : URichTextBlock(FObjectInitializer::Get()) {
    this->bOverrideDefaultSize = true;
    this->OverrideDefaultFontSize = 12;
    this->bOverrideDefaultColor = false;
}

void URichTextSizable::SetDefaultFontSize(int32 InFontSize) {
}

void URichTextSizable::SetDefaultFontColor(const FLinearColor& InColor) {
}


