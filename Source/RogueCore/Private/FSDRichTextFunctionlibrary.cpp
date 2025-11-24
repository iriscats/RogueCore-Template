#include "FSDRichTextFunctionlibrary.h"

UFSDRichTextFunctionlibrary::UFSDRichTextFunctionlibrary() {
}

void UFSDRichTextFunctionlibrary::SplitRichText(const FRichTextParseResult& Parser, int32 SplitIndex, bool bKeepLeftFormatting, bool bKeepRightFormatting, FText& OutLeftText, FText& OutRightText) {
}

FText UFSDRichTextFunctionlibrary::RemoveRichTextTags(const FText& InText) {
    return FText::GetEmpty();
}

FRichTextParseResult UFSDRichTextFunctionlibrary::ParseRichText(const FText& InText) {
    return FRichTextParseResult{};
}

FText UFSDRichTextFunctionlibrary::MidRichText(const FRichTextParseResult& Parser, int32 StartIndex, int32 count, bool bKeepFormatting) {
    return FText::GetEmpty();
}


