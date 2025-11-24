#include "AccessCondition.h"

UAccessCondition::UAccessCondition() {
}

TArray<UAccessCondition*> UAccessCondition::GetLinkedConditions() const {
    return TArray<UAccessCondition*>();
}

FText UAccessCondition::GetDenyText() const {
    return FText::GetEmpty();
}

TSoftObjectPtr<USoundCue> UAccessCondition::GetDenySound() const {
    return NULL;
}

TSoftObjectPtr<UDialogDataAsset> UAccessCondition::GetDenyShout() const {
    return NULL;
}


