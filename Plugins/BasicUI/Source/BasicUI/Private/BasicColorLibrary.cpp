#include "BasicColorLibrary.h"

UBasicColorLibrary::UBasicColorLibrary() {
}

FBasicColor UBasicColorLibrary::LinearToBasicColor(const FLinearColor& InColor) {
    return FBasicColor{};
}

FSlateColor UBasicColorLibrary::BasicToSlateColor(const FBasicColor& InBasicColor) {
    return FSlateColor{};
}

FLinearColor UBasicColorLibrary::BasicToLinearColor(const FBasicColor& InBasicColor) {
    return FLinearColor{};
}

FLinearColor UBasicColorLibrary::AssetToLinearColor(UBasicColorAsset* InReferenceColor) {
    return FLinearColor{};
}

FBasicColor UBasicColorLibrary::AssetToBasicColor(UBasicColorAsset* InReferenceColor) {
    return FBasicColor{};
}


