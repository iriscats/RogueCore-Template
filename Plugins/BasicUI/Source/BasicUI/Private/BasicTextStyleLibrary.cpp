#include "BasicTextStyleLibrary.h"

UBasicTextStyleLibrary::UBasicTextStyleLibrary() {
}

FBasicTextStyle UBasicTextStyleLibrary::TextBlockStyleToBasicTextStyle(const FTextBlockStyle& InTextStyle) {
    return FBasicTextStyle{};
}

FTextBlockStyle UBasicTextStyleLibrary::BasicToTextBlockStyle(const FBasicTextStyle& InBasicTextStyle) {
    return FTextBlockStyle{};
}

FBasicTextStyle UBasicTextStyleLibrary::AssetToBasicColor(UBasicTextStyleAsset* InTextStyleAsset) {
    return FBasicTextStyle{};
}


