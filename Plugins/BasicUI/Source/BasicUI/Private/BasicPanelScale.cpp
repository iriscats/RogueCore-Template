#include "BasicPanelScale.h"

FBasicPanelScale::FBasicPanelScale() {
    this->HorizontalAlignment = HAlign_Fill;
    this->VerticalAlignment = VAlign_Fill;
    this->Stretch = EStretch::Type::None;
    this->StretchDirection = EStretchDirection::Type::Both;
    this->UserSpecifiedScale = 0.00f;
}

