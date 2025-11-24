#include "SavableDataAsset.h"

USavableDataAsset::USavableDataAsset() {
    this->EnableDangerousSaveGameIDEditing = false;
    this->BuildRestriction = NULL;
}

FGuid USavableDataAsset::GetSaveGameID() const {
    return FGuid{};
}


