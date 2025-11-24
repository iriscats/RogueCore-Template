#include "BasicBrushLibrary.h"

UBasicBrushLibrary::UBasicBrushLibrary() {
}

FBasicBrush UBasicBrushLibrary::SlateToBasicBrush(const FSlateBrush& InBrush) {
    return FBasicBrush{};
}

FSlateBrush UBasicBrushLibrary::BasicToSlateBrush(const FBasicBrush& InBasicBrush) {
    return FSlateBrush{};
}

FBasicBrush UBasicBrushLibrary::AssetToBasicBrush(UBasicBrushAsset* InAsset) {
    return FBasicBrush{};
}


