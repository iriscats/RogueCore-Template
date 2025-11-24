#include "RichTextIconDecorator.h"

URichTextIconDecorator::URichTextIconDecorator() : URichTextBlockDecorator(FObjectInitializer::Get()) {
    this->WidgetClass = NULL;
    this->bEmbedToolTipText = false;
}

void URichTextIconDecorator::SetEmbedToolTipText(bool InEmbed) {
}


