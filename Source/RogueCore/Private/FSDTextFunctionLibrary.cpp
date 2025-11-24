#include "FSDTextFunctionLibrary.h"

UFSDTextFunctionLibrary::UFSDTextFunctionLibrary() {
}

FText UFSDTextFunctionLibrary::TextFromInt(float Value, int32 MinimumDigits) {
    return FText::GetEmpty();
}

FText UFSDTextFunctionLibrary::TextFromFloat(float Value, int32 FractionalDigits) {
    return FText::GetEmpty();
}

FText UFSDTextFunctionLibrary::TextAsPercentage(float Value, int32 MaxFractionalDigits) {
    return FText::GetEmpty();
}

FText UFSDTextFunctionLibrary::AppendTextNewLine(const FText& Text1, const FText& Text2) {
    return FText::GetEmpty();
}

FText UFSDTextFunctionLibrary::AppendTextDoubleNewLine(const FText& Text1, const FText& Text2) {
    return FText::GetEmpty();
}

FText UFSDTextFunctionLibrary::AppendText(const FText& Text1, const FText& Text2, const FText& Delimiter) {
    return FText::GetEmpty();
}


