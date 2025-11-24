#include "DialogDataAsset.h"

UDialogDataAsset::UDialogDataAsset() {
    this->Enabled = true;
    this->AudioOnly = false;
    this->SelectUsingWeight = false;
    this->ShoutDelay = 0.00f;
    this->ShoutCoolDown = 2.00f;
    this->ShoutChance = 1.00f;
}

bool UDialogDataAsset::SelectEntry(const UObject* WorldContext, EDialogVoice Voice, FDialogStruct& Dialog) {
    return false;
}


