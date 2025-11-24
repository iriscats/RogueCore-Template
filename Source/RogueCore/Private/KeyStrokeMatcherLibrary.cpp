#include "KeyStrokeMatcherLibrary.h"

UKeyStrokeMatcherLibrary::UKeyStrokeMatcherLibrary() {
}

bool UKeyStrokeMatcherLibrary::TestKeyStroke(FKeyStrokeMatcher& KeyStrokeMatcher, const FKeyEvent& InKey) {
    return false;
}

void UKeyStrokeMatcherLibrary::ReleaseKeyStroke(FKeyStrokeMatcher& KeyStrokeMatcher, const FKeyEvent& InKey) {
}


