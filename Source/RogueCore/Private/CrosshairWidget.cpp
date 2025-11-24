#include "CrosshairWidget.h"

UCrosshairWidget::UCrosshairWidget() : UUserWidget(FObjectInitializer::Get()) {
}



FVector2D UCrosshairWidget::GetExtensionOffset_Implementation() const {
    return FVector2D{};
}


